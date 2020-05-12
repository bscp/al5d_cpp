// HEADER INCLUDE
#include <al5d_cpp/base/configs/PoseConfig.hpp>


namespace al5d
{
    PoseConfig::PoseConfig(
        const PoseName& name,
        const JointNameDegreeList& joint_name_degree_list)
        : name(name)
        , joint_name_degree_list(joint_name_degree_list)
    {
    }
}
