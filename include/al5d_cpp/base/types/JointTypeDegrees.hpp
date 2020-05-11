#ifndef AL5D_CPP_JOINTTYPEDEGREES_HPP
#define AL5D_CPP_JOINTTYPEDEGREES_HPP

// SYSTEM INCLUDES
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/types/JointType.hpp>
#include <al5d_cpp/base/types/Degrees.hpp>


namespace al5d
{
    struct JointTypeDegrees
    {
        const JointType joint_type;
        const Degrees degrees;

        JointTypeDegrees(
            const JointType& joint_type,
            const Degrees &degrees);
    };
    
    typedef std::vector<JointTypeDegrees> JointTypeDegreesList;
}


#endif // AL5D_CPP_JOINTTYPEDEGREES_HPP
