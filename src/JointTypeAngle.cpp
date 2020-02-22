
// HEADER INCLUDE
#include <al5d_cpp/JointTypeAngle.hpp>

namespace al5d
{
    JointTypeAngle::JointTypeAngle(
        const JointType& joint_type,
        const JointAngle &joint_angle)
        : joint_type(joint_type)
        , joint_angle(joint_angle)
    {
    }
}
