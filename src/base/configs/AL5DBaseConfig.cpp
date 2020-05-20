// HEADER INCLUDE
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions.hpp>


namespace al5d
{
    AL5DBaseConfig::AL5DBaseConfig(
        JointBaseConfigs joint_configs,
        SerialConfig serial_config,
        PosingConfig posing_config)
        : joint_configs(std::move(joint_configs))
        , serial_config(std::move(serial_config))
        , posing_config(std::move(posing_config))
    {
        validate_joint_configs();
    }


    void AL5DBaseConfig::validate_joint_configs()
        const
    {
        if (joint_configs.size() != 6)
        {
            throw InvalidNumberOfJoints((int)joint_configs.size());
        }
    }
}
