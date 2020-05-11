// HEADER INCLUDE
#include <al5d_cpp/base/types/JointTypeDegrees.hpp>


namespace al5d
{
    JointTypeDegrees::JointTypeDegrees(
        const JointType& joint_type,
        const Degrees &degrees)
        : joint_type(joint_type)
        , degrees(degrees)
    {
    }
}
