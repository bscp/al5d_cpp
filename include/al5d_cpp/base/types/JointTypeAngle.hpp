#ifndef AL5D_CPP_JOINTTYPEANGLE_HPP
#define AL5D_CPP_JOINTTYPEANGLE_HPP

// SYSTEM INCLUDES
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/types/JointType.hpp>
#include <al5d_cpp/base/types/Angle.hpp>


namespace al5d
{
    struct JointTypeAngle
    {
        const JointType joint_type;
        const Angle angle;

        JointTypeAngle(
            const JointType& joint_type,
            const Angle& angle);
    };
    
    typedef std::vector<JointTypeAngle> JointTypeAngles;
}


#endif // AL5D_CPP_JOINTTYPEANGLE_HPP
