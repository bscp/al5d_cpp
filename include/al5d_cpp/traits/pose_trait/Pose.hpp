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
            const JointTypeDegreeList& joint_type_degree_list);
        
        const PoseName name;
        const JointTypeDegreeList joint_type_degree_list;
    };

    typedef std::vector<Pose> Poses;
}


#endif // AL5D_CPP_POSE_HPP
