#ifndef AL5D_CPP_LOGLINES_HPP
#define AL5D_CPP_LOGLINES_HPP

// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d_cpp
{
    std::string get_moving_joint_log_line(
        const JointTypeAngle &joint_type_angle,
        const PulseWidth& pulse_width);

    std::string get_moving_joint_log_line(
        const JointTypeAngle &joint_type_angle,
        const PulseWidth& pulse_width,
        const Duration &duration);
}


#endif // AL5D_CPP_LOGLINES_HPP
