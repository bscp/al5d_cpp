#ifndef AL5D_CPP_POSE_HPP
#define AL5D_CPP_POSE_HPP

// SYSTEM INCLUDES
#include <string>
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>
#include <al5d_cpp/base/configs/PoseConfig.hpp>


namespace al5d
{
    struct Pose
    {
        Pose(
            const PoseName& name,
            const JointTypeDegrees& joint_type_degrees);
        
        const PoseName name;
        const JointTypeDegrees joint_type_degrees;
    };

    typedef std::vector<Pose> Poses;
}


#endif // AL5D_CPP_POSE_HPP
