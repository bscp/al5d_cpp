// TODO : make file which includes all Config types at once

#ifndef AL5D_CPP_AL5DBASECONFIG_HPP
#define AL5D_CPP_AL5DBASECONFIG_HPP

// SYSTEM INCLUDES
#include <vector>
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/JointConfig.hpp>
#include <al5d_cpp/base/types.hpp>
#include <al5d_cpp/base/configs/SerialConfig.hpp>
#include <al5d_cpp/base/configs/PosingConfig.hpp>


namespace al5d
{
    struct AL5DBaseConfig
    {
        AL5DBaseConfig(
            JointConfigs joint_configs,
            SerialConfig serial_config,
            PosingConfig posing_config);
        
        void validate_joint_configs()
            const;

        const JointConfigs joint_configs;
        const SerialConfig serial_config;
        const PosingConfig posing_config;
    };
}


#endif // AL5D_CPP_AL5DBASECONFIG_HPP
