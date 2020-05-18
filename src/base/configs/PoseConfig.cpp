// HEADER INCLUDE
#include <al5d_cpp/base/configs/PoseConfig.hpp>


namespace al5d
{
    PoseConfig::PoseConfig(
        const PoseName& name,
        const JointNameAngles& joint_name_angles)
        : name(name)
        , joint_name_angles(joint_name_angles)
    {
    }
}
