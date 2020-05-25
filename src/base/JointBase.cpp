// HEADER INCLUDE
#include <al5d_cpp/base/JointBase.hpp>

// SYSTEM INCLUDES
#include <stdexcept>
#include <cmath>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions.hpp>
#include <al5d_cpp/logging.hpp>


namespace al5d_cpp
{
    JointBase::JointBase(
        const JointBaseConfig &joint_config)
        : name__(joint_config.name)
        , type__(joint_config.type)
        , board_channel__(joint_config.board_channel)
        , degree_range__(joint_config.degree_range)
        , pulse_width_range__(joint_config.pulse_width_range)
        , convert_ratio__(calculate_convert_ratio__())
        , communicator_ptr__(nullptr)
    {
    }

    
    double JointBase::calculate_convert_ratio__()
        const
    {
        return pulse_width_range__.get_difference() / degree_range__.get_difference();
    }


    bool JointBase::has_name(
        const JointName& name)
        const
    {
        return this->name__ == name;
    }


    bool JointBase::has_type(
        const JointType &type)
        const
    {
        return this->type__ == type;
    }


    JointType JointBase::get_type()
        const
    {
        return type__;
    }

    
    void JointBase::move_to_angle(
        const Angle& angle)
        const
    {
        const auto pulse_width = to_pulse_width__(angle);
        log_moving__(angle, pulse_width);
        transmit_pulse_width__(pulse_width);
    }
    
    
    void JointBase::move_to_angle(
        const Angle& angle,
        const Duration& move_duration)
        const
    {
        const auto pulse_width = to_pulse_width__(angle);
        log_moving__(angle, pulse_width, move_duration);
        transmit_pulse_width__(pulse_width);
        transmit_move_duration__(move_duration);
    }
    
    
    void JointBase::transmit_pulse_width__(
        const PulseWidth& pulse_width)
        const
    {
        std::string command("#" + std::to_string(board_channel__));
        command += "P" + std::to_string(pulse_width.value);
        transmit__(command);
    }
    
    
    void JointBase::stop()
        const
    {
        transmit__("STOP " + std::to_string(board_channel__) + "\r");
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

        auto abs_degree = std::abs(angle.in_degree().value - degree_range__.value_1.value);
        auto abs_pulse_width = abs_degree * convert_ratio__;
        auto pulse_width = abs_pulse_width + pulse_width_range__.min.value;
        return PulseWidth((PulseWidth::Value)pulse_width);
    }
    
    
    void JointBase::validate_reachability__(
        const Angle& angle)
        const
    {
        const auto degree = angle.in_degree();
        if (!degree_range__.is_within_range(degree))
        {
            LOG_ERROR("degree out of range");
            throw DegreeOutOfRange(degree);
        }
    }


    void JointBase::set_communicator_ptr(
        const CommunicatorBasePtr& communicator_ptr)
    {
        this->communicator_ptr__ = communicator_ptr;
    }


    void JointBase::validate_communicator_ptr__()
        const
    {
        if (communicator_ptr__ == nullptr)
        {
            throw MissingCommunicator();
        }
    }
    
    
    void JointBase::transmit__(
        const ProtocolCommand& message)
        const
    {
        validate_communicator_ptr__();
        communicator_ptr__->transmit(message);
    }


    void JointBase::log_moving__(
        const Angle &angle,
        const PulseWidth& pulse_width)
        const
    {
        LOG_INFO(get_log_moving__(
            angle, pulse_width));
    }
    
    
    void JointBase::log_moving__(
        const Angle &angle,
        const PulseWidth& pulse_width,
        const Duration &move_duration)
        const
    {
        LOG_INFO(get_log_moving__(
            angle, pulse_width, move_duration));
    }


    std::string JointBase::get_log_moving__(
        const Angle& angle,
        const PulseWidth& pulse_width)
        const
    {
        const auto type_string = "Name='" + name__ + "'";
        const auto angle_string = "Degree='" + std::to_string(angle.in_degree().value) + "' PulseWidth='" + std::to_string(pulse_width.value) + "'";
        return "MOVING_JOINT :: " + type_string + " " + angle_string;
    }
    
    
    std::string JointBase::get_log_moving__(
        const Angle& angle,
        const PulseWidth& pulse_width,
        const Duration &duration)
        const
    {
        auto log_line = get_log_moving__(angle, pulse_width);
        return log_line + " Duration='" + std::to_string(duration.in_milliseconds()) + "ms'";
    }
}
