// HEADER INCLUDE
#include <al5d_cpp/base/AL5DBase.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions.hpp>


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
        const ProtocolCommand& message)
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
        const ProtocolCommand &command)
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
    
    
    const JointBase &AL5DBase::get_joint(
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
    
    
    const JointBase &AL5DBase::get_joint(
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

        throw InvalidJointType();
    }
    
    
    void AL5DBase::stop()
    {
        transmit_command_("STOP");
    }


    void AL5DBase::move_to_angles(
        const JointNameAngles &joint_name_angles,
        const Duration &move_duration)
    {
        for (const auto &joint_name_angle : joint_name_angles)
        {
            const auto& joint = get_joint(joint_name_angle.joint_name);
            joint.move_to_angle(joint_name_angle.angle, move_duration);
        }
        transmit_command_terminator_();
    }


    void AL5DBase::move_to_angles(
        const JointNameAngles &joint_name_angles)
    {
        for (const auto &joint_name_angle : joint_name_angles)
        {
            const auto& joint = get_joint(joint_name_angle.joint_name);
            joint.move_to_angle(joint_name_angle.angle);
        }
        transmit_command_terminator_();
    }


    void AL5DBase::move_to_angles(
        const JointTypeAngles &joint_type_angles,
        const Duration &move_duration)
    {
        for (const auto &joint_type_angle : joint_type_angles)
        {
            const auto& joint = get_joint(joint_type_angle.joint_type);
            joint.move_to_angle(joint_type_angle.angle, move_duration);
        }
        transmit_command_terminator_();
    }


    void AL5DBase::move_to_angles(
        const JointTypeAngles &joint_type_angles)
    {
        for (const auto &joint_type_angle : joint_type_angles)
        {
            const auto& joint = get_joint(joint_type_angle.joint_type);
            joint.move_to_angle(joint_type_angle.angle);
        }
        transmit_command_terminator_();
    }
}
