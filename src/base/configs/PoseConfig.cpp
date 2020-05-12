// HEADER INCLUDE
#include <al5d_cpp/base/configs/PoseConfig.hpp>


namespace al5d
{
    PoseConfig::PoseConfig(
        const PoseName& name,
        const JointNameDegrees& joint_name_degrees)
        : name(name)
        , joint_name_degrees(joint_name_degrees)
    {
    }
}
