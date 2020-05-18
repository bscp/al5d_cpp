#ifndef AL5D_CPP_JOINTNAMEANGLE_HPP
#define AL5D_CPP_JOINTNAMEANGLE_HPP

// SYSTEM INCLUDES
#include <string>
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/types/Angle.hpp>


namespace al5d
{
    struct JointNameAngle
    {
        const std::string joint_name;
        const Angle angle;

        JointNameAngle(
            const std::string& joint_name,
            const Angle& angle);
    };

    typedef std::vector<JointNameAngle> JointNameAngles;
}


#endif // AL5D_CPP_JOINTNAMEANGLE_HPP
