#ifndef AL5D_CPP_AL5DBASECONFIG_HPP
#define AL5D_CPP_AL5DBASECONFIG_HPP

// SYSTEM INCLUDES
#include <vector>
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/PosingConfig.hpp>
#include <al5d_cpp/base/configs/JointBaseConfig.hpp>
#include <al5d_cpp/base/configs/SerialConfig.hpp>
#include <al5d_cpp/base/types.hpp>


namespace al5d_cpp
{
    struct AL5DBaseConfig
    {
        AL5DBaseConfig(
            JointBaseConfigs joint_configs,
            SerialConfig serial_config,
            PosingConfig posing_config);

        const JointBaseConfigs joint_configs;
        const SerialConfig serial_config;
        const PosingConfig posing_config;

    private:
        
        void validate_joint_configs()
            const;
    };
}


#endif // AL5D_CPP_AL5DBASECONFIG_HPP
