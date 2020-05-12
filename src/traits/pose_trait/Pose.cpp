// HEADER INCLUDE
#include <al5d_cpp/traits/pose_trait/Pose.hpp>


namespace al5d
{
    Pose::Pose(
        const PoseName& name,
        const JointTypeDegreeList& joint_type_degree_list)
        : name(name)
        , joint_type_degree_list(joint_type_degree_list)
    {
    }
}
