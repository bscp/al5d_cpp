// HEADER INCLUDE
#include <al5d_cpp/base/JointBase.hpp>

// SYSTEM INCLUDES
#include <stdexcept>
#include <cmath>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>
#include <al5d_cpp/exceptions.hpp>


namespace al5d
{
    JointBase::JointBase(
        const JointBaseConfig &joint_config)
        : name(joint_config.name)
        , type(joint_config.type)
        , board_channel(joint_config.board_channel)
        , degree_range(joint_config.degree_range)
        , pulse_width_range(joint_config.pulse_width_range)
        , convert_ratio(calculate_convert_ratio__())
        , communicator_ptr(nullptr)
    {
    }

    
    double JointBase::calculate_convert_ratio__()
        const
    {
        return pulse_width_range.get_difference() / degree_range.get_difference();
    }


    bool JointBase::has_name(
        const JointName& name)
        const
    {
        return this->name == name;
    }


    bool JointBase::has_type(
        const JointType &type)
        const
    {
        return this->type == type;
    }


    JointType JointBase::get_type()
        const
    {
        return type;
    }

    
    void JointBase::move_to_angle(
        const Angle& angle)
        const
    {
        transmit_angle__(angle);
    }
    
    
    void JointBase::move_to_angle(
        const Angle& angle,
        const Duration& move_duration)
        const
    {
        transmit_angle__(angle);
        transmit_move_duration__(move_duration);
    }
    
    
    void JointBase::transmit_angle__(
        const Angle& angle)
        const
    {
        const auto angle_in_pulse_width = to_pulse_width__(angle);

        std::string command("#" + std::to_string(board_channel));
        command += "P" + std::to_string(angle_in_pulse_width.value);        

        transmit__(command);
    }
    
    
    void JointBase::stop()
        const
    {
        transmit__("STOP " + std::to_string(board_channel) + "\r");
    }
    
    
    void JointBase::transmit_move_duration__(
        const Duration& move_duration)
        const
    {
        auto milliseconds = move_duration.in_milliseconds();
        if (milliseconds > 0)
        {
            transmit__("T" + std::to_string(milliseconds));    
        }
    }
    
    
    PulseWidth JointBase::to_pulse_width__(
        const Angle& angle)
        const
    {
        validate_reachability__(angle);

        auto abs_degree = std::abs(angle.in_degree().value - degree_range.value_1.value);
        auto abs_pulse_width = abs_degree * convert_ratio;
        auto pulse_width = abs_pulse_width + pulse_width_range.min.value;
        return PulseWidth((PulseWidth::Value)pulse_width);
    }
    
    
    void JointBase::validate_reachability__(
        const Angle& angle)
        const
    {
        const auto degree = angle.in_degree();
        if (!degree_range.is_within_range(degree))
        {
            LOG_ERROR("degree out of range");
            throw DegreeOutOfRange(degree);
        }
    }


    void JointBase::set_communicator_ptr(
        const CommunicatorPtr& communicator_ptr)
    {
        this->communicator_ptr = communicator_ptr;
    }


    void JointBase::validate_communicator_ptr__()
        const
    {
        if (communicator_ptr == nullptr)
        {
            throw MissingCommunicator();
        }
    }
    
    
    void JointBase::transmit__(
        const ProtocolCommand& message)
        const
    {
        validate_communicator_ptr__();
        communicator_ptr->transmit(message);
    }
}
