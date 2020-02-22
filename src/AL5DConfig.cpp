
// HEADER INCLUDE
#include <al5d_cpp/AL5DConfig.hpp>

namespace al5d
{
    AL5DConfig::AL5DConfig(std::vector<JointConfig> jointConfigs)
        : joint_configs(std::move(jointConfigs))
    {
    }
}
