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
        
        virtual void move_to_angles(
            const JointNameAngles &joint_name_angles,
            const Duration &move_duration);
    
        virtual void move_to_angles(
            const JointTypeAngles &joint_type_angles,
            const Duration &move_duration);
        
        virtual void move_to_angles(
            const JointNameAngles &joint_name_angles);
    
        virtual void move_to_angles(
            const JointTypeAngles &joint_type_angles);
            
        virtual void stop();

        void set_communicator_ptr(
            const CommunicatorPtr& communicator_ptr);
        
        bool is_ready() // TODO : remove ?
            const;

        const JointBase &get_joint(
            const JointType &joint_type)
            const;
    
        const JointBase &get_joint(
            const JointName& joint_name)
            const;

    protected:

        explicit AL5DBase(
            const AL5DBaseConfig& config);
        
        virtual void transmit_command_(
            const Command &command)
            const;
        
        virtual void transmit_command_terminator_()
            const;
            
        JointBases joints_;

        CommunicatorPtr communicator_ptr_ = nullptr;
            
    private:

        void validate_communicator_ptr__()
            const;
    
        static void move_to__(
            const JointBase& joint,
            const Degree &degree,
            const Duration &move_duration);
    
        static void move_to__(
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
