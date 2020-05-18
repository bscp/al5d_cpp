// HEADER INCLUDE
#include <al5d_cpp/traits/pose_trait/Pose.hpp>


namespace al5d
{
    Pose::Pose(
        const PoseName& name,
        const JointTypeAngles& joint_type_angles)
        : name(name)
        , joint_type_angles(joint_type_angles)
    {
    }
}
