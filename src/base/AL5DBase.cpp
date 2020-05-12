// HEADER INCLUDE
#include <al5d_cpp/base/AL5DBase.hpp>

// SYSTEM INCLUDES
#include <iostream>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions/MissingCommunicator.hpp>


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
    }
    
    
    void AL5DBase::construct_joints(
        const JointConfigs& joint_configs)
    {
        for (const auto& joint_config : joint_configs)
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
            throw MissingCommunicator();
        }
    }
    
    
    bool AL5DBase::is_ready()
        const
    {
        validate_communicator_ptr();
        return communicator_ptr->is_ready();
    }
    
    
    void AL5DBase::transmit(
        const std::string& message)
        const
    {
        validate_communicator_ptr();
        communicator_ptr->transmit(message);
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
        const JointName& joint_name)
        const
    {
        // TODO : strip spaces
        // TODO : to lowercase
        
        for (const auto& joint : joints)
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
        for (const auto& joint : joints)
        {
            if (joint.has_type(joint_type))
            {
                return joint;
            }
        }

        throw "Joint not found"; // TODO : throw class
    }
    
    
    void AL5DBase::move_to_degree(
        const JointType& joint_type,
        const Degree &degree,
        const Duration &move_duration)
    {
        move_to_degrees({{joint_type, degree}}, move_duration);
    }
    
    
    void AL5DBase::move_to_degrees(
        const JointTypeDegreeList &joint_type_degree_list,
        const Duration &move_duration)
    {
        for (const auto &joint_type_degree : joint_type_degree_list)
        {
            const auto &joint_type = joint_type_degree.joint_type;
            const auto &joint_angle = joint_type_degree.degree.value;
            const auto &joint = get_joint(joint_type);
            joint.move_to(Degree(joint_angle));
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
