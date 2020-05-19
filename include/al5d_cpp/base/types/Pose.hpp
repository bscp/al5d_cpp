#ifndef AL5D_CPP_POSE_HPP
#define AL5D_CPP_POSE_HPP

// SYSTEM INCLUDES
#include <string>
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/types/typedefs.hpp>
#include <al5d_cpp/base/types/JointTypeAngle.hpp>


namespace al5d
{
    typedef std::string PoseName;

    struct Pose
    {
        Pose(
            const PoseName& name,
            const JointTypeAngles& joint_type_angles);
        
        const PoseName name;
        const JointTypeAngles joint_type_angles;
    };

    typedef std::vector<Pose> Poses;
}


#endif // AL5D_CPP_POSE_HPP
