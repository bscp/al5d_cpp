#ifndef AL5D_CPP_POSINGCONFIG_HPP
#define AL5D_CPP_POSINGCONFIG_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/PoseConfig.hpp>


namespace al5d
{
    struct PosingConfig
    {
        PosingConfig(
            const PoseConfigs& pose_configs,
            const PoseName& start_pose_name,
            const PoseName& finish_pose_name);
        
        const PoseConfigs pose_configs;
        const PoseName start_pose_name;
        const PoseName finish_pose_name;
    };
}


#endif // AL5D_CPP_POSINGCONFIG_HPP
