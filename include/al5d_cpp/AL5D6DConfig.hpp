
#ifndef AL5D_CPP_AL5D6DCONFIG_HPP
#define AL5D_CPP_AL5D6DCONFIG_HPP

// PROJECT INCLUDES
#include <al5d_cpp/JointConfig.hpp>
#include <al5d_cpp/types.hpp>

namespace al5d
{
    struct AL5D6DConfig
    {
        AL5D6DConfig();

        JointConfig base_joint_config;
        JointConfig shoulder_joint_config;
        JointConfig elbow_joint_config;
        JointConfig wrist_joint_config;
        JointConfig gripper_joint_config;
        JointConfig wrist_rotate_joint_config;
    };
}

#endif // AL5D_CPP_AL5D6DCONFIG_HPP
