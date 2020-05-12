// HEADER INCLUDE
#include <al5d_cpp/traits/pose_trait/Pose.hpp>


namespace al5d
{
    Pose::Pose(
        const PoseName& name,
        const JointTypeDegrees& joint_type_degrees)
        : name(name)
        , joint_type_degrees(joint_type_degrees)
    {
    }
}
