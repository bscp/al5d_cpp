// HEADER INCLUDE
#include <al5d_cpp/base/configs/PosingConfig.hpp>


namespace al5d_cpp
{
    PosingConfig::PosingConfig(
        const PoseConfigs& pose_configs,
        const PoseName& calibrating_pose_name,
        const PoseName& start_pose_name,
        const PoseName& finish_pose_name)
        : pose_configs(pose_configs)
        , calibrating_pose_name(calibrating_pose_name)
        , start_pose_name(start_pose_name)
        , finish_pose_name(finish_pose_name)
    {
    }
}
