// HEADER INCLUDE
#include <al5d_cpp/base/configs/PoseConfig.hpp>


namespace al5d
{
    PoseConfig::PoseConfig(
        const std::string& name,
        const JointNameDegreesList& joint_name_degrees_list)
        : name(name)
        , joint_name_degrees_list(joint_name_degrees_list)
    {
    }
}
