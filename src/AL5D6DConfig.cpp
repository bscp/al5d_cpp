
// HEADER INCLUDE
#include <al5d_cpp/AL5D6DConfig.hpp>

namespace al5d
{
    AL5D6DConfig::AL5D6DConfig()
        : base_joint_config(0, 500, 2500, -90, 90)
        , shoulder_joint_config(1, 500, 2500, -30, 90)
        , elbow_joint_config(2, 500, 2500, 0, 135)
        , wrist_joint_config(3, 500, 2500, -90, 90)
        , gripper_joint_config(4, 500, 2500, 0, 1)
        , wrist_rotate_joint_config(5, 500, 2500, -90, 90)
    {
    }
}
