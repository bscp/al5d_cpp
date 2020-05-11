// HEADER INCLUDE
#include <al5d_cpp/AL5D_logging.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>


namespace al5d
{
    void log_emergency_stop()
    {
        LOG_INFO("EMERGENCY_STOP");
    }

    
    void log_transmit_command(
        const std::string& command)
    {
        LOG_INFO("TRANSMITTING :: " + command);
    }
    
    
    void log_moving_joint(
        const JointTypeDegrees &joint_type_degrees)
    {
        LOG_DEBUG(get_moving_joint_log(joint_type_degrees));
    }
    
    
    void log_moving_joint(
        const JointTypeDegrees &joint_type_degrees,
        const Duration &duration)
    {
        LOG_DEBUG(get_moving_joint_log(joint_type_degrees, duration));
    }
    
    
    void log_moving_joints(
        const JointTypeDegreesList &joint_type_degrees_list)
    {
        for (const auto& joint_type_degrees : joint_type_degrees_list)
        {
            log_moving_joint(joint_type_degrees);
        }
    }
    
    
    void log_moving_joints(
        const JointTypeDegreesList &joint_type_degrees_list,
        const Duration& duration)
    {
        for (const auto& joint_type_degrees : joint_type_degrees_list)
        {
            LOG_INFO(get_moving_joint_log(joint_type_degrees, duration));
        }
    }
    
    
    std::string get_moving_joint_log(
        const JointTypeDegrees &joint_type_degrees)
    {
        const auto type_string = "Type='" + std::to_string(joint_type_degrees.joint_type) + "'";
        const auto angle_string = "Angle='" + std::to_string(joint_type_degrees.degrees.value) + "pwm'";
        return "MOVING_JOINT :: " + type_string + " " + angle_string;
    }
    
    
    std::string get_moving_joint_log(
        const JointTypeDegrees &joint_type_degrees,
        const Duration &duration)
    {
        auto log = get_moving_joint_log(joint_type_degrees);
        return log + " Duration='" + std::to_string(duration.in_milliseconds()) + "ms'";
    }
}
