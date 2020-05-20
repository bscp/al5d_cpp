// HEADER INCLUDE
#include <al5d_cpp/base/types/JointTypeAngle.hpp>


namespace al5d_cpp
{
    JointTypeAngle::JointTypeAngle(
        const JointType& joint_type,
        const Angle& angle)
        : joint_type(joint_type)
        , angle(angle)
    {
    }
}
