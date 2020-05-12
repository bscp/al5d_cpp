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
        const JointTypeDegree &joint_type_degree)
    {
        LOG_DEBUG(get_moving_joint_log(joint_type_degree));
    }
    
    
    void log_moving_joint(
        const JointTypeDegree &joint_type_degree,
        const Duration &duration)
    {
        LOG_DEBUG(get_moving_joint_log(joint_type_degree, duration));
    }
    
    
    void log_moving_joints(
        const JointTypeDegrees &joint_type_degrees)
    {
        for (const auto& joint_type_degree : joint_type_degrees)
        {
            log_moving_joint(joint_type_degree);
        }
    }
    
    
    void log_moving_joints(
        const JointTypeDegrees &joint_type_degrees,
        const Duration& duration)
    {
        for (const auto& joint_type_degree : joint_type_degrees)
        {
            LOG_INFO(get_moving_joint_log(joint_type_degree, duration));
        }
    }
    
    
    std::string get_moving_joint_log(
        const JointTypeDegree &joint_type_degree)
    {
        const auto type_string = "Type='" + std::to_string(joint_type_degree.joint_type) + "'";
        const auto angle_string = "Angle='" + std::to_string(joint_type_degree.degree.value) + "pwm'";
        return "MOVING_JOINT :: " + type_string + " " + angle_string;
    }
    
    
    std::string get_moving_joint_log(
        const JointTypeDegree &joint_type_degree,
        const Duration &duration)
    {
        auto log = get_moving_joint_log(joint_type_degree);
        return log + " Duration='" + std::to_string(duration.in_milliseconds()) + "ms'";
    }
}
