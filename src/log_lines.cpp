
// HEADER INCLUDE
#include <al5d_cpp/log_lines.hpp>


namespace al5d_cpp
{
//     void log_emergency_stop()
//     {
//         LOG_INFO("EMERGENCY_STOP");
//     }
    
    
//     void log_no_serial_connection()
//     {
//         LOG_ERROR("No connection connection established");
//     }
    
    
//     void log_connecting(
//         const SerialPort &serial_port,
//         const BaudRate &serial_baud_rate)
//     {
//         LOG_INFO(get_connecting_log(serial_port, serial_baud_rate));
//     }
    
    
//     void log_disconnecting()
//     {
//         LOG_INFO(get_disconnecting_log());
//     }
    
    
//     void log_moving_joint(
//         const JointTypeAngle &joint_type_angle)
//     {
//         LOG_DEBUG(get_moving_joint_log(joint_type_angle));
//     }
    
    
//     void log_moving_joint(
//         const JointTypeAngle &joint_type_angle,
//         const Duration &duration)
//     {
//         LOG_DEBUG(get_moving_joint_log(joint_type_angle, duration));
//     }
    
    
//     void log_moving_joints(
//         const JointTypeAngles &joint_type_angles)
//     {
//         for (const auto& joint_type_angle : joint_type_angles)
//         {
//             log_moving_joint(joint_type_angle);
//         }
//     }
    
    
//     void log_moving_joints(
//         const JointTypeAngles &joint_type_angles,
//         const Duration& duration)
//     {
//         for (const auto& joint_type_angle : joint_type_angles)
//         {
//             LOG_INFO(get_moving_joint_log(joint_type_angle, duration));
//         }
//     }
    
    
//     std::string get_connecting_log(
//         const SerialPort &serial_port,
//         const BaudRate &serial_baud_rate)
//     {
//         const std::string method_string = "Method='SERIAL'";
//         const std::string port_string = "Port='" + serial_port + "'";
//         const std::string angle_string = "Baud='" + std::to_string(serial_baud_rate.value()) + "'";
//         return "CONNECTING :: " + method_string + " " + port_string + " " + angle_string;
//     }
    
    
//     std::string get_disconnecting_log()
//     {
//         return "DISCONNECTING_SERIAL";
//     }
}