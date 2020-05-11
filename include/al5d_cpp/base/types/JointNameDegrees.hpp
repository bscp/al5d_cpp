#ifndef AL5D_CPP_JOINTNAMEDEGREES_HPP
#define AL5D_CPP_JOINTNAMEDEGREES_HPP

// SYSTEM INCLUDES
#include <string>
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    struct JointNameDegrees
    {
        JointNameDegrees(
            const std::string& joint_name,
            const Degrees& degrees);
        
        const std::string joint_name;
        const Degrees degrees;
    };

    typedef std::vector<JointNameDegrees> JointNameDegreesList;
}


#endif // AL5D_CPP_JOINTNAMEDEGREES_HPP
