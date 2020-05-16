// HEADER INCLUDE
#include <al5d_cpp/base/AL5DBase.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions/MissingCommunicator.hpp>


namespace al5d
{   
    AL5DBase::AL5DBase(
        const AL5DBaseConfig& config)
        : joints_(construct_joints__(config.joint_configs))
        , communicator_ptr_(nullptr)
    {
    }
    
    
    AL5DBase::~AL5DBase()
    {
    }
    
    
    JointBases AL5DBase::construct_joints__(
        const JointConfigs& joint_configs)
    {
        JointBases join_bases;

        for (const auto& joint_config : joint_configs)
        {
            joints_.push_back(JointBase(joint_config));
        }

        return join_bases;
    }


    void AL5DBase::validate_communicator_ptr__()
        const
    {
        if (communicator_ptr_ == nullptr)
        {
            throw MissingCommunicator();
        }
    }
    
    
    bool AL5DBase::is_ready()
        const
    {
        validate_communicator_ptr__();
        return communicator_ptr_->is_ready();
    }
    
    
    void AL5DBase::transmit__(
        const std::string& message)
        const
    {
        validate_communicator_ptr__();
        communicator_ptr_->transmit(message);
    }

    
    void AL5DBase::transmit_command_terminator_()
        const
    {
        transmit__("\r");
    }
    
    
    void AL5DBase::transmit_command_(
        const Command &command)
        const
    {
        transmit__(command);
        transmit_command_terminator_();
    }


    void AL5DBase::set_communicator_ptr(
        const CommunicatorPtr& communicator_ptr)
    {
        communicator_ptr_ = communicator_ptr;
        set_joint_communicator_ptrs__();
    }


    void AL5DBase::set_joint_communicator_ptrs__()
    {
        for (auto& joint : joints_)
        {
            joint.set_communicator_ptr(communicator_ptr_);
        }
    }
    
    
    const JointBase &AL5DBase::get_joint_(
        const JointName& joint_name)
        const
    {
        // TODO : strip spaces
        // TODO : to lowercase
        
        for (const auto& joint : joints_)
        {
            if (joint.has_name(joint_name))
            {
                return joint;
            }
        }

        throw "Joint not found"; // TODO : throw class
    }
    
    
    const JointBase &AL5DBase::get_joint_(
        const JointType &joint_type)
        const
    {
        for (const auto& joint : joints_)
        {
            if (joint.has_type(joint_type))
            {
                return joint;
            }
        }

        throw "Joint not found"; // TODO : throw class
    }
    
    
    void AL5DBase::stop()
    {
        transmit_command_("STOP");
    }


    void AL5DBase::move_to_degree(
        const JointName& joint_name,
        const Degree &degree)
    {
        move_to_degree__(
            get_joint_(joint_name),
            degree);
        transmit_command_terminator_();
    }


    void AL5DBase::move_to_degree(
        const JointName& joint_name,
        const Degree &degree,
        const Duration &move_duration)
    {
        move_to_degree__(
            get_joint_(joint_name),
            degree,
            move_duration);
        transmit_command_terminator_();
    }


    void AL5DBase::move_to_degree(
        const JointType& joint_type,
        const Degree &degree)
    {
        move_to_degree__(
            get_joint_(joint_type),
            degree);
        transmit_command_terminator_();
    }


    void AL5DBase::move_to_degree(
        const JointType& joint_type,
        const Degree &degree,
        const Duration &move_duration)
    {
        move_to_degree__(
            get_joint_(joint_type),
            degree,
            move_duration);
        transmit_command_terminator_();
    }


    void AL5DBase::move_to_degree__(
        const JointBase& joint,
        const Degree &degree)
    {
        joint.move_to(degree);
    }


    void AL5DBase::move_to_degree__(
        const JointBase& joint,
        const Degree &degree,
        const Duration &move_duration)
    {
        joint.move_to(degree, move_duration);
    }


    void AL5DBase::move_to_degrees(
        const JointNameDegrees &joint_name_degrees,
        const Duration &move_duration)
    {
        for (const auto &joint_name_degree : joint_name_degrees)
        {
            move_to_degree__(
                get_joint_(joint_name_degree.joint_name),
                joint_name_degree.degree,
                move_duration);
        }
        transmit_command_terminator_();
    }


    void AL5DBase::move_to_degrees(
        const JointNameDegrees &joint_name_degrees)
    {
        for (const auto &joint_name_degree : joint_name_degrees)
        {
            move_to_degree__(
                get_joint_(joint_name_degree.joint_name),
                joint_name_degree.degree);
        }
        transmit_command_terminator_();
    }


    void AL5DBase::move_to_degrees(
        const JointTypeDegrees &joint_type_degrees,
        const Duration &move_duration)
    {
        for (const auto &joint_type_degree : joint_type_degrees)
        {
            move_to_degree__(
                get_joint_(joint_type_degree.joint_type),
                joint_type_degree.degree,
                move_duration);
        }
        transmit_command_terminator_();
    }


    void AL5DBase::move_to_degrees(
        const JointTypeDegrees &joint_type_degrees)
    {
        for (const auto &joint_type_degree : joint_type_degrees)
        {
            move_to_degree__(
                get_joint_(joint_type_degree.joint_type),
                joint_type_degree.degree);
        }
        transmit_command_terminator_();
    }
}
