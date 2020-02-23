
// HEADER INCLUDE
#include <al5d_cpp/AL5DConfig.hpp>

namespace al5d
{
    AL5DConfig::AL5DConfig(
        std::string &serial_port,
        long serial_baudrate,
        JointConfigs &joint_configs)
        : serial_port(std::move(serial_port))
        , serial_baudrate(serial_baudrate)
        , joint_configs(std::move(joint_configs))
    {
    }
}
