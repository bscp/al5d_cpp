#ifndef AL5D_CPP_AL5D_LOGGING_HPP
#define AL5D_CPP_AL5D_LOGGING_HPP

#include <al5d_cpp/AL5D.hpp>


namespace al5d
{
    void log_moving_joint(
        const JointTypeAngle &joint_type_angle);
    
    void log_moving_joint(
        const JointTypeAngle &joint_type_angle,
        const Duration &duration);
    
    void log_moving_joints(
        const JointTypeAngles &joint_type_angles);
    
    void log_moving_joints(
        const JointTypeAngles &joint_type_angles,
        const Duration &duration);
    
    std::string get_moving_joint_log(
        const JointTypeAngle &joint_type_angle);
    
    std::string get_moving_joint_log(
        const JointTypeAngle &joint_type_angle,
        const Duration &duration);
    
    std::string get_connecting_log(
        const SerialPort &serial_port,
        const BaudRate &serial_baud_rate);
    
    void log_connecting(
        const SerialPort &serial_port,
        const BaudRate &serial_baud_rate);
    
    void log_emergency_stop();
    
    void log_no_serial_connection();
    
    void log_disconnecting();
    
    std::string get_disconnecting_log();
}


#endif // AL5D_CPP_AL5D_LOGGING_HPP
