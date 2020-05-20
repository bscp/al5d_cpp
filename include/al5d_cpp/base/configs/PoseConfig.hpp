#ifndef AL5D_CPP_POSECONFIG_HPP
#define AL5D_CPP_POSECONFIG_HPP

// SYSTEM INCLUDES
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d_cpp
{
    struct PoseConfig
    {
        PoseConfig(
            const PoseName& name,
            const JointNameAngles& joint_name_angles);
        
        const PoseName name;
        const JointNameAngles joint_name_angles;
    };

    typedef std::vector<PoseConfig> PoseConfigs;
}


#endif // AL5D_CPP_POSECONFIG_HPP
