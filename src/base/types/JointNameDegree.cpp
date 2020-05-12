// HEADER INCLUDE
#include <al5d_cpp/base/types/JointNameDegree.hpp>


namespace al5d
{
    JointNameDegree::JointNameDegree(
        const std::string& joint_name,
        const Degree& degree)
        : joint_name(joint_name)
        , degree(degree)
    {
    }
}
