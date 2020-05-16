#ifndef AL5D_CPP_AL5DBASE_HPP
#define AL5D_CPP_AL5DBASE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/Duration.hpp>
#include <al5d_cpp/base/JointBase.hpp>
#include <al5d_cpp/base/types.hpp>
#include <al5d_cpp/base/configs/JointConfig.hpp>
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>
#include <al5d_cpp/base/settings.hpp>
#include <al5d_cpp/base/Communicator.hpp>


namespace al5d
{
    class AL5DBase
    {
    public:
        typedef AL5DBaseConfig Config;
    
        virtual ~AL5DBase();
    
        virtual void move_to_degree(
            const JointName& joint_name,
            const Degree &degree,
            const Duration &move_duration);
    
        virtual void move_to_degree(
            const JointType& joint_type,
            const Degree &degree,
            const Duration &move_duration);
            
        virtual void move_to_degree(
            const JointName& joint_name,
            const Degree &degree);
    
        virtual void move_to_degree(
            const JointType& joint_type,
            const Degree &degree);
        
        virtual void move_to_degrees(
            const JointNameDegrees &joint_name_degrees,
            const Duration &move_duration);
    
        virtual void move_to_degrees(
            const JointTypeDegrees &joint_type_degrees,
            const Duration &move_duration);
        
        virtual void move_to_degrees(
            const JointNameDegrees &joint_name_degrees);
    
        virtual void move_to_degrees(
            const JointTypeDegrees &joint_type_degrees);
            
        virtual void stop();

        void set_communicator_ptr(
            const CommunicatorPtr& communicator_ptr);
        
        bool is_ready()
            const;

    protected:

        explicit AL5DBase(
            const AL5DBaseConfig& config);
        
        virtual void transmit_command_(
            const Command &command)
            const;
        
        virtual void transmit_command_terminator_()
            const;

        const JointBase &get_joint_(
            const JointType &joint_type)
            const;
    
        const JointBase &get_joint_(
            const JointName& joint_name)
            const;
            
        JointBases joints_;

        CommunicatorPtr communicator_ptr_ = nullptr;
            
    private:

        void validate_communicator_ptr__()
            const;
    
        void move_to_degree__(
            const JointBase& joint,
            const Degree &degree,
            const Duration &move_duration);
    
        void move_to_degree__(
            const JointBase& joint,
            const Degree &degree);

        void transmit__(
            const std::string& message)
            const;
    
        JointBases construct_joints__(
            const JointConfigs& joint_configs);

        void set_joint_communicator_ptrs__();
    };
}


#endif // AL5D_CPP_AL5DBASE_HPP
