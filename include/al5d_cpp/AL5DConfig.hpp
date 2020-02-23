
#ifndef AL5D_CPP_AL5DCONFIG_HPP
#define AL5D_CPP_AL5DCONFIG_HPP

// SYSTEM INCLUDES
#include <vector>
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/JointConfig.hpp>
#include <al5d_cpp/types.hpp>

namespace al5d
{
    struct AL5DConfig
    {
        const std::string serial_port;
        const long serial_baudrate;
        const JointConfigs joint_configs;

        AL5DConfig(
            std::string &serial_port,
            long serial_baudrate,
            JointConfigs &joint_configs);
    };
}

#endif // AL5D_CPP_AL5DCONFIG_HPP
