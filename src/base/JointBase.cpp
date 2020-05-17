// HEADER INCLUDE
#include <al5d_cpp/base/JointBase.hpp>

// SYSTEM INCLUDES
#include <stdexcept>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>
#include <al5d_cpp/exceptions.hpp>


namespace al5d
{
    JointBase::JointBase(
        const JointConfig &joint_config)
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

    
    void JointBase::move_to(
        const Degree& degree)
        const
    {
        transmit_degree__(degree);
    }
    
    
    void JointBase::move_to(
        const Degree& degree,
        const Duration& move_duration)
        const
    {
        transmit_degree__(degree);
        transmit_move_duration__(move_duration);
    }
    
    
    void JointBase::transmit_degree__(
        const Degree& degree)
        const
    {
        validate_reachability__(degree);

        std::string command("#" + std::to_string(board_channel));
        command += "P" + std::to_string(to_pulse_width__(degree).value);        

        transmit__(command);
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
        Degree degree)
        const
    {
        validate_reachability__(degree);
        auto abs_deg = degree.value - degree_range.min.value;
        auto abs_pwm = abs_deg * convert_ratio;
        auto pwm = abs_pwm + pulse_width_range.min.value;
        return PulseWidth(PulseWidth::Value(pwm));
    }
    
    
    void JointBase::validate_reachability__(
        Degree degree)
        const
    {
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
        const std::string& message)
        const
    {
        validate_communicator_ptr__();
        communicator_ptr->transmit(message);
    }
}
