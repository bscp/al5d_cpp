#ifndef AL5D_CPP_AL5DBASE_HPP
#define AL5D_CPP_AL5DBASE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/JointBase.hpp>
#include <al5d_cpp/base/types.hpp>
#include <al5d_cpp/base/configs/JointBaseConfig.hpp>
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>
#include <al5d_cpp/base/CommunicatorBase.hpp>
#include <al5d_cpp/Timer.hpp>
#include <al5d_cpp/base/configs/PosingConfig.hpp>


namespace al5d_cpp
{
    class AL5DBase
    {
    public:
        virtual void move_to_angles(
            const JointNameAngles &joint_name_angles,
            Duration move_duration);
    
        virtual void move_to_angles(
            const JointTypeAngles &joint_type_angles,
            Duration move_duration);
        
        virtual void move_to_angles(
            const JointNameAngles &joint_name_angles);
    
        virtual void move_to_angles(
            const JointTypeAngles &joint_type_angles);
            
        virtual void stop();

        void set_communicator_ptr(
            const CommunicatorBasePtr& communicator_ptr);
        
        bool is_connected()
            const;

        const JointBase &get_joint(
            const JointType &joint_type)
            const;
    
        const JointBase &get_joint(
            JointName joint_name)
            const;
            
        bool is_moving()
            const;
        
        void move_to_pose(
            const PoseName& pose_name);

        void move_to_pose(
            const PoseName& pose_name,
            const Duration &move_duration);

        void add_poses(
            const PosingConfig& posing_config);

        void set_poses(
            const PosingConfig& posing_config);
    
        void move_to_calibrating_pose();

        void move_to_start_pose();
        
        void move_to_finish_pose();

    protected:

        explicit AL5DBase(
            const AL5DBaseConfig& config);
        
        virtual void transmit_command_(
            const ProtocolCommand &command)
            const;
        
        virtual void transmit_command_terminator_()
            const;
            
        JointBases joints_;

        CommunicatorBasePtr communicator_ptr_ = nullptr;

    private:

        void validate_communicator_ptr__()
            const;

        static Duration default_if_zero__(
            const Duration &move_duration);
    
        static void move_to__(
            const JointBase& joint,
            const Degree &degree,
            const Duration &move_duration);
    
        static void move_to__(
            const JointBase& joint,
            const Degree &degree);

        void start_timer__(
            const Duration &move_duration);

        void transmit__(
            const ProtocolCommand& message)
            const;
    
        JointBases construct_joints__(
            const JointBaseConfigs& joint_configs);

        void set_joint_communicator_ptrs__();

        static void log_moving_to_angles__(
            size_t angle_count);
        
        static void log_moving_to_angles__(
            size_t angle_count,
            const Duration &move_duration);

        static std::string get_log_moving_to_angles__(
            size_t angle_count);
        
        static std::string get_log_moving_to_angles__(
            size_t angle_count,
            const Duration &duration);
        
        JointType construct_poses__(
            const JointName& joint_name)
            const;

        JointTypeAngle construct_poses__(
            const JointNameAngle& joint_name_angle)
            const;

        JointTypeAngles construct_poses__(
            const JointNameAngles& joint_name_angles)
            const;
            
        Pose construct_poses__(
            const PoseConfig& pose_config)
            const;

        Poses construct_poses__(
            const PoseConfigs& pose_configs)
            const;

        const Pose& get_pose__(
            const PoseName& pose_name)
            const;

        static void log_moving_to_pose__(
            const PoseName& pose_name);

        static void log_moving_to_pose__(
            const PoseName& pose_name,
            const Duration &move_duration);

        static std::string get_log_moving_to_pose__(
            const PoseName& pose_name);
        
        static std::string get_log_moving_to_pose__(
            const PoseName& pose_name,
            const Duration &duration);

        // timer is used because al5d did not respond to
        // the position request commands
        TimerPtr timer_ptr__;
        Poses poses__;
        PoseName calibrating_pose_name__;
        PoseName start_pose_name__;
        PoseName finish_pose_name__;
    };
}


#endif // AL5D_CPP_AL5DBASE_HPP
