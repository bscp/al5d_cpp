// HEADER INCLUDE
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions/InvalidNumberOfJoints.hpp>


namespace al5d
{
    AL5DBaseConfig::AL5DBaseConfig(
        JointConfigs joint_configs,
        SerialConfig serial_config,
        PoseConfigs pose_configs)
        : joint_configs(std::move(joint_configs))
        , serial_config(std::move(serial_config))
        , pose_configs(std::move(pose_configs))
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
