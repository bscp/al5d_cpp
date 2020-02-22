
#ifndef AL5D_CPP_AL5DCONFIG_HPP
#define AL5D_CPP_AL5DCONFIG_HPP

// SYSTEM INCLUDES
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/JointConfig.hpp>
#include <al5d_cpp/types.hpp>

namespace al5d
{
    struct AL5DConfig
    {
        std::vector<JointConfig> joint_configs;

        explicit AL5DConfig(std::vector<JointConfig> jointConfigs);
    };
}

#endif // AL5D_CPP_AL5DCONFIG_HPP
