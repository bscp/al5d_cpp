
// HEADER INCLUDE
#include <al5d_cpp/AL5DConfig.hpp>

namespace al5d
{
    AL5DConfig::AL5DConfig(
        JointConfigs joint_configs)
        : joint_configs(std::move(joint_configs))
    {
    }
}
