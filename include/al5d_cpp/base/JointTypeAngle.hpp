
#ifndef AL5D_CPP_JOINTTYPEANGLE_HPP
#define AL5D_CPP_JOINTTYPEANGLE_HPP

// SYSTEM INCLUDES
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/JointAngle.hpp>
#include <al5d_cpp/base/JointType.hpp>

namespace al5d
{
    struct JointTypeAngle
    {
        const JointType joint_type;
        const JointAngle joint_angle;

        JointTypeAngle(
            const JointType& joint_type,
            const JointAngle &joint_angle);
    };
    
    typedef std::vector<JointTypeAngle> JointTypeAngles;
}

#endif // AL5D_CPP_JOINTTYPEANGLE_HPP
