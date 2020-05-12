#ifndef AL5D_CPP_AL5D_LOGGING_HPP
#define AL5D_CPP_AL5D_LOGGING_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/AL5DBase.hpp>


namespace al5d
{
    void log_moving_joint(
        const JointTypeDegree &joint_type_degree);
    
    void log_moving_joint(
        const JointTypeDegree &joint_type_degree,
        const Duration &duration);
    
    void log_moving_joints(
        const JointTypeDegrees &joint_type_degrees);
    
    void log_moving_joints(
        const JointTypeDegrees &joint_type_degrees,
        const Duration &duration);
    
    std::string get_moving_joint_log(
        const JointTypeDegree &joint_type_degree);
    
    std::string get_moving_joint_log(
        const JointTypeDegree &joint_type_degree,
        const Duration &duration);
    
    void log_emergency_stop();
    
    void log_disconnecting();
    
    void log_transmit_command(
        const std::string& command);
}


#endif // AL5D_CPP_AL5D_LOGGING_HPP
