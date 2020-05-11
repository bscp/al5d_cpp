#ifndef AL5D_CPP_AL5D_LOGGING_HPP
#define AL5D_CPP_AL5D_LOGGING_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/AL5DBase.hpp>


namespace al5d
{
    void log_moving_joint(
        const JointTypeDegrees &joint_type_degrees);
    
    void log_moving_joint(
        const JointTypeDegrees &joint_type_degrees,
        const Duration &duration);
    
    void log_moving_joints(
        const JointTypeDegreesList &joint_type_degrees_list);
    
    void log_moving_joints(
        const JointTypeDegreesList &joint_type_degrees_list,
        const Duration &duration);
    
    std::string get_moving_joint_log(
        const JointTypeDegrees &joint_type_degrees);
    
    std::string get_moving_joint_log(
        const JointTypeDegrees &joint_type_degrees,
        const Duration &duration);
    
    void log_emergency_stop();
    
    void log_disconnecting();
    
    void log_transmit_command(
        const std::string& command);
}


#endif // AL5D_CPP_AL5D_LOGGING_HPP
