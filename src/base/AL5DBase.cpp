// HEADER INCLUDE
#include <al5d_cpp/base/AL5DBase.hpp>

// SYSTEM INCLUDES
#include <iostream>


namespace al5d
{   
    AL5DBase::AL5DBase(
        const AL5DBaseConfig& config)
        : joints()
        , communicator_ptr(nullptr)
    {
        construct_joints(config.joint_configs);
    }
    
    
    AL5DBase::~AL5DBase()
    {
        disconnect();
    }
    
    
    void AL5DBase::construct_joints(
        const JointConfigs& joints_configs)
    {
        for (const auto& joint_config : joints_configs)
        {
            const auto joint = JointBase(joint_config);
            joints.push_back(joint);
        }
    }


    void AL5DBase::validate_communicator_ptr()
        const
    {
        if (communicator_ptr == nullptr)
        {
            throw "communicator is nullptr"; // TODO : throw class
        }
    }
    
    
    void AL5DBase::transmit(
        const std::string& message)
        const
    {
        validate_communicator_ptr();
        communicator_ptr->transmit(message);
    }
    
    
    void AL5DBase::connect()
    {
        // TODO : throw no connect process implemented
    }
    
    
    bool AL5DBase::is_connected()
    {
        return true;
    }
    
    
    void AL5DBase::disconnect()
    {
        // TODO : throw no disconnect process implemented
    }
    
    
    void AL5DBase::terminate_command()
        const
    {
        transmit("\r");
    }
    
    
    void AL5DBase::transmit_command(
        const Command &command)
        const
    {
        transmit(command);
        terminate_command();
    }


    void AL5DBase::set_communicator_ptr(
        const CommunicatorPtr& communicator_ptr)
    {
        this->communicator_ptr = communicator_ptr;
        set_joint_communicator_ptrs();
    }


    void AL5DBase::set_joint_communicator_ptrs()
    {
        for (auto& joint : joints)
        {
            joint.set_communicator_ptr(communicator_ptr);
        }
    }
    
    
    const JointBase &AL5DBase::get_joint(
        const JointType &joint_type)
    const
    {
        return joints.at(joint_type);
    }
    
    
    void AL5DBase::move_to(
        const JointTypeAngle &joint_type_angle,
        const Duration &move_duration)
    {
        move_to({joint_type_angle}, move_duration);
    }
    
    
    void AL5DBase::move_to(
        const JointTypeAngles &joint_type_angles,
        const Duration &move_duration)
    {
        for (const auto &joint_type_angle : joint_type_angles)
        {
            const auto &joint_type = joint_type_angle.joint_type;
            const auto &joint_angle = joint_type_angle.joint_angle;
            const auto &joint = get_joint(joint_type);
            joint.move_to(joint_angle);
        }
        
        auto milliseconds = move_duration.in_milliseconds();
        auto duration_command = "T" + std::to_string(milliseconds);

        transmit_command(duration_command);
    }
    
    
    void AL5DBase::stop()
    {
        transmit_command("STOP");
    }
}
