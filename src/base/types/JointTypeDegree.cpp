// HEADER INCLUDE
#include <al5d_cpp/base/types/JointTypeDegree.hpp>


namespace al5d
{
    JointTypeDegree::JointTypeDegree(
        const JointType& joint_type,
        const Degree &degree)
        : joint_type(joint_type)
        , degree(degree)
    {
    }
}
