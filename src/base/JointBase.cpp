// HEADER INCLUDE
#include <al5d_cpp/base/JointBase.hpp>

// SYSTEM INCLUDES
#include <stdexcept>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>
#include <al5d_cpp/exceptions/MissingCommunicator.hpp>


namespace al5d
{
    JointBase::JointBase(
        const JointConfig &joint_config)
        : joint_name(joint_config.joint_name)
        , board_channel(joint_config.board_channel)
        , min_pulse_width(joint_config.min_pulse_width)
        , max_pulse_width(joint_config.max_pulse_width)
        , min_degrees(joint_config.min_degrees)
        , max_degrees(joint_config.max_degrees)
        , lowest_degrees(get_lowest_degrees())
        , highest_degrees(get_highest_degrees())
        , degrees_range(max_degrees - min_degrees)
        , pulse_width_range(max_pulse_width - min_pulse_width)
        , convert_ratio(double(pulse_width_range) / double(degrees_range))
        , communicator_ptr(nullptr)
    {
    }


    Degrees JointBase::get_lowest_degrees()
        const
    {
        return min_degrees <= max_degrees ? min_degrees : max_degrees;
    }


    Degrees JointBase::get_highest_degrees()
        const
    {
        return min_degrees <= max_degrees ? max_degrees : min_degrees;
    }

    
    void JointBase::move_to(
        const Degrees& degrees)
        const
    {
        validate_degrees(degrees);

        std::string command("#");
        command += std::to_string(board_channel);
        command += "P" + std::to_string(to_pulse_width(degrees));        

        transmit(command);
    }
    
    
    JointAngle JointBase::to_pulse_width(Degrees degrees) const
    {
        validate_degrees(degrees);
        return JointAngle((degrees - min_degrees) * convert_ratio + min_pulse_width);
    }
    
    
    void JointBase::validate_degrees(Degrees degrees) const
    {
        if (!can_reach_degrees(degrees))
        {
            LOG_ERROR("degrees out of range");
            throw std::invalid_argument("degrees out of range");
        }
    }
    
    
    bool JointBase::can_reach_degrees(const Degrees &degrees) const
    {
        bool above_lower_bound = lowest_degrees <= degrees;
        bool below_upper_bound = degrees <= highest_degrees;
        return above_lower_bound && below_upper_bound;
    }


    void JointBase::set_communicator_ptr(
        const CommunicatorPtr& communicator_ptr)
    {
        this->communicator_ptr = communicator_ptr;
    }


    void JointBase::validate_communicator_ptr()
        const
    {
        if (communicator_ptr == nullptr)
        {
            throw MissingCommunicator();
        }
    }
    
    
    void JointBase::transmit(
        const std::string& message)
        const
    {
        validate_communicator_ptr();
        communicator_ptr->transmit(message);
    }
}
