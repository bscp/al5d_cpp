#ifndef AL5D_CPP_LOGGINGROBOT_TPP
#define	AL5D_CPP_LOGGINGROBOT_TPP

// PROJECT INCLUDES
#include <al5d_cpp/AL5D_logging.hpp>


namespace al5d
{
    template <typename BaseType>
    LoggingRobot<BaseType>::LoggingRobot(
        const Config& config)
        : BaseType(config)
    {
    }
    
    
    template <typename BaseType>
    void LoggingRobot<BaseType>::move_to(
        const JointTypeAngles &joint_type_angles)
    {
        log_moving_joints(joint_type_angles);
        BaseType::move_to(joint_type_angles);
    }
    
    
    template <typename BaseType>
    void LoggingRobot<BaseType>::move_to(
        const JointTypeAngle &joint_type_angle)
    {
        log_moving_joint(joint_type_angle);
        BaseType::move_to(joint_type_angle);
    }
    
    
    template <typename BaseType>
    void LoggingRobot<BaseType>::move_to(
        const JointTypeAngles &joint_type_angles,
        const Duration &move_duration)
    {
        log_moving_joints(joint_type_angles, move_duration);
        BaseType::move_to(joint_type_angles, move_duration);
    }
    
    
    template <typename BaseType>
    void LoggingRobot<BaseType>::move_to(
        const JointTypeAngle &joint_type_angle,
        const Duration &move_duration)
    {
        log_moving_joint(joint_type_angle, move_duration);
        BaseType::move_to(joint_type_angle, move_duration);
    }
    
    
    template <typename BaseType>
    void LoggingRobot<BaseType>::do_emergency_stop()
    {
        log_emergency_stop();
        BaseType::do_emergency_stop();
    }

    
    template <typename BaseType>
    void LoggingRobot<BaseType>::transmit_command(
        const Command &command)
    {
        log_transmit_command(command);
        BaseType::transmit_command(command);
    }
}


#endif	/* AL5D_CPP_LOGGINGROBOT_TPP */
