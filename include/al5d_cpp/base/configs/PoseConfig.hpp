#ifndef AL5D_CPP_POSECONFIG_HPP
#define AL5D_CPP_POSECONFIG_HPP

// SYSTEM INCLUDES
#include <string>
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    struct PoseConfig
    {
        PoseConfig(
            const PoseName& name,
            const JointNameDegreesList& joint_name_degrees_list);
        
        const PoseName name;
        const JointNameDegreesList joint_name_degrees_list;
    };

    typedef std::vector<PoseConfig> PoseConfigs;
}


#endif // AL5D_CPP_POSECONFIG_HPP
