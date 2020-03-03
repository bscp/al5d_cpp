
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
    
    
    void log_no_serial_connection()
    {
        LOG_ERROR("No connection connection established");
    }
    
    
    void log_connecting(
        const SerialPort &serial_port,
        const BaudRate &serial_baud_rate)
    {
        LOG_INFO(get_connecting_log(serial_port, serial_baud_rate));
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
        const SerialPort &serial_port,
        const BaudRate &serial_baud_rate)
    {
        const std::string method_string = "Method='SERIAL'";
        const std::string port_string = "Port='" + serial_port + "'";
        const std::string angle_string = "Baud='" + std::to_string(serial_baud_rate.value()) + "'";
        return "CONNECTING :: " + method_string + " " + port_string + " " + angle_string;
    }
    
    
    std::string get_disconnecting_log()
    {
        return "DISCONNECTING_SERIAL";
    }
    
    
    std::string get_moving_joint_log(
        const JointTypeAngle &joint_type_angle)
    {
        const auto type_string = "Type='" + std::to_string(joint_type_angle.joint_type) + "'";
        const auto angle_string = "Angle='" + std::to_string(joint_type_angle.joint_angle) + "pwm'";
        return "MOVING_JOINT :: " + type_string + " " + angle_string;
    }
    
    
    std::string get_moving_joint_log(
        const JointTypeAngle &joint_type_angle,
        const Duration &duration)
    {
        auto log = get_moving_joint_log(joint_type_angle);
        return log + " Duration='" + std::to_string(duration.in_milliseconds()) + "ms'";
    }
}
