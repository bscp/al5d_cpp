// HEADER INCLUDE
#include <al5d_cpp/base/types/JointNameDegrees.hpp>


namespace al5d
{
    JointNameDegrees::JointNameDegrees(
        const std::string& joint_name,
        const Degrees& degrees)
        : joint_name(joint_name)
        , degrees(degrees)
    {
    }
}
