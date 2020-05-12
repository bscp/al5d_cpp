#ifndef AL5D_CPP_TYPES_HPP
#define AL5D_CPP_TYPES_HPP

// SYSTEM INCLUDES
#include <cstdint>
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/base/types/JointType.hpp>
#include <al5d_cpp/base/types/JointTypeDegree.hpp>
#include <al5d_cpp/base/types/PulseWidth.hpp>
#include <al5d_cpp/base/types/PulseWidthRange.hpp>
#include <al5d_cpp/base/types/Degree.hpp>
#include <al5d_cpp/base/types/DegreeRange.hpp>
#include <al5d_cpp/base/types/JointNameDegree.hpp>


namespace al5d
{
    typedef std::string JointName;
    typedef std::string PoseName;
    typedef std::string Command;
    typedef unsigned int BoardChannel;
}


#endif // AL5D_CPP_TYPES_HPP
