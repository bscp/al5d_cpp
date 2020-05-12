#ifndef AL5D_CPP_JOINTNAMEDEGREE_HPP
#define AL5D_CPP_JOINTNAMEDEGREE_HPP

// SYSTEM INCLUDES
#include <string>
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    struct JointNameDegree
    {
        const std::string joint_name;
        const Degree degree;

        JointNameDegree(
            const std::string& joint_name,
            const Degree& degree);
    };

    typedef std::vector<JointNameDegree> JointNameDegrees;
}


#endif // AL5D_CPP_JOINTNAMEDEGREE_HPP
