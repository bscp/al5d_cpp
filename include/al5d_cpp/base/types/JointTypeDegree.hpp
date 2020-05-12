#ifndef AL5D_CPP_JOINTTYPEDEGREE_HPP
#define AL5D_CPP_JOINTTYPEDEGREE_HPP

// SYSTEM INCLUDES
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/types/JointType.hpp>
#include <al5d_cpp/base/types/Degree.hpp>


namespace al5d
{
    struct JointTypeDegree
    {
        const JointType joint_type;
        const Degree degree;

        JointTypeDegree(
            const JointType& joint_type,
            const Degree &degree);
    };
    
    typedef std::vector<JointTypeDegree> JointTypeDegrees;
}


#endif // AL5D_CPP_JOINTTYPEDEGREE_HPP
