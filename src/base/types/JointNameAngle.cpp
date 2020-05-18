// HEADER INCLUDE
#include <al5d_cpp/base/types/JointNameAngle.hpp>


namespace al5d
{
    JointNameAngle::JointNameAngle(
        const std::string& joint_name,
        const Angle& angle)
        : joint_name(joint_name)
        , angle(angle)
    {
    }
}
