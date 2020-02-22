
// HEADER INCLUDE
#include <al5d_cpp/AL5D.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>

namespace al5d
{
    void log_emergency_stop()
    {
        LOG_INFO("EMERGENCY_STOP");
    }
    
    
    void log_no_serial_connection()
    {
        LOG_ERROR("No serial connection established");
    }
    
    
    void log_constructing()
    {
        LOG_INFO("CONSTRUCTING_AL5D :: DEFAULT_CONFIG");
    }
    
    
    void log_connecting(
        const std::string& serial_port,
        long serial_baudrate)
    {
        LOG_INFO(get_connecting_log(serial_port, serial_baudrate));
    }
    
    
    void log_disconnecting()
    {
        LOG_INFO(get_disconnecting_log());
    }
    
    
    void log_moving_joint(
        const JointTypeAngle &joint_type_angle)
    {
        LOG_DEBUG(get_moving_joint_log(joint_type_angle));
    }
    
    
    void log_moving_joint(
        const JointTypeAngle &joint_type_angle,
        const Duration &duration)
    {
        LOG_DEBUG(get_moving_joint_log(joint_type_angle, duration));
    }
    
    
    void log_moving_joints(
        const JointTypeAngles &joint_type_angles)
    {
        for (const auto& joint_type_angle : joint_type_angles)
        {
            log_moving_joint(joint_type_angle);
        }
    }
    
    
    void log_moving_joints(
        const JointTypeAngles &joint_type_angles,
        const Duration& duration)
    {
        for (const auto& joint_type_angle : joint_type_angles)
        {
            LOG_INFO(get_moving_joint_log(joint_type_angle, duration));
        }
    }
    
    
    std::string get_connecting_log(
        const std::string &serial_port,
        long serial_baudrate)
    {
        const auto type_string = "PORT='" + serial_port + "'";
        const auto angle_string = "BAUD='" + std::to_string(serial_baudrate) + "'";
        return "CONNECTING_SERIAL :: " + type_string + " " + angle_string;
    }
    
    
    std::string get_disconnecting_log()
    {
        return "DISCONNECTING_SERIAL";
    }
    
    
    std::string get_moving_joint_log(
        const JointTypeAngle &joint_type_angle)
    {
        const auto type_string = "TYPE='" + std::to_string(joint_type_angle.joint_type) + "'";
        const auto angle_string = "ANGLE='" + std::to_string(joint_type_angle.joint_angle) + "pwm'";
        return "MOVING_JOINT :: " + type_string + " " + angle_string;
    }
    
    
    std::string get_moving_joint_log(
        const JointTypeAngle &joint_type_angle,
        const Duration &duration)
    {
        auto log = get_moving_joint_log(joint_type_angle);
        return log + " DURATION='" + std::to_string(duration.in_milliseconds()) + "ms'";
    }
}
