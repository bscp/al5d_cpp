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
        : name(joint_config.name)
        , type(joint_config.type)
        , board_channel(joint_config.board_channel)
        , degrees_range(joint_config.degrees_range)
        , pulse_width_range(joint_config.pulse_width_range)
        , convert_ratio(get_convert_ratio())
        , communicator_ptr(nullptr)
    {
    }

    
    double JointBase::get_convert_ratio()
        const
    {
        return pulse_width_range.get_difference() / degrees_range.get_difference();
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
        const Degrees& degrees)
        const
    {
        validate_reachability(degrees);
        auto pulse_width = to_pulse_width(degrees);

        std::string command("#");
        command += std::to_string(board_channel);
        command += "P" + std::to_string(pulse_width.value);        

        transmit(command);
    }
    
    
    PulseWidth JointBase::to_pulse_width(
        Degrees degrees)
        const
    {
        validate_reachability(degrees);
        return PulseWidth(PulseWidth::Value((degrees.value - degrees_range.value_1.value) * convert_ratio + pulse_width_range.min.value)); // TODO : shorten this line
    }
    
    
    void JointBase::validate_reachability(Degrees degrees) const
    {
        if (!degrees_range.is_within_range(degrees))
        {
            LOG_ERROR("degrees out of range");
            throw std::invalid_argument("degrees out of range"); // TODO : throw a class
        }
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
