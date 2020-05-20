// HEADER INCLUDES
#include <al5d_cpp/base/types/Pose.hpp>


namespace al5d_cpp
{
    Pose::Pose(
        const PoseName& name,
        const JointTypeAngles& joint_type_angles)
        : name(name)
        , joint_type_angles(joint_type_angles)
    {
    }
}
