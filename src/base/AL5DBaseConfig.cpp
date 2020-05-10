// HEADER INCLUDE
#include <al5d_cpp/base/AL5DBaseConfig.hpp>


namespace al5d
{
    AL5DBaseConfig::AL5DBaseConfig(
        JointConfigs joint_configs,
        SerialConfig serial_config)
        : joint_configs(std::move(joint_configs))
        , serial_config(std::move(serial_config))
    {
        validate_joint_configs();
    }


    void AL5DBaseConfig::validate_joint_configs()
        const
    {
        if (joint_configs.size() != 6)
        {
            throw "Not the expected number of joints in config"; // TODO : throw as class
        }
    }
}
