#ifndef AL5D_CPP_AL5DCONFIG_HPP
#define AL5D_CPP_AL5DCONFIG_HPP

// SYSTEM INCLUDES
#include <vector>
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/JointConfig.hpp>
#include <al5d_cpp/types.hpp>
#include <al5d_cpp/types.hpp>


namespace al5d
{
    struct AL5DBaseConfig
    {
        JointConfigs joint_configs;
    };
}


#endif // AL5D_CPP_AL5DCONFIG_HPP
