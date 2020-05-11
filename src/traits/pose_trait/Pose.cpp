// HEADER INCLUDE
#include <al5d_cpp/traits/pose_trait/Pose.hpp>


namespace al5d
{
    Pose::Pose(
        const PoseName& name,
        const JointTypeDegreesList& joint_type_degrees_list)
        : name(name)
        , joint_type_degrees_list(joint_type_degrees_list)
    {
    }
}
