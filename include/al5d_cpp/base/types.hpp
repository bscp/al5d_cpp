#ifndef AL5D_CPP_TYPES_HPP
#define AL5D_CPP_TYPES_HPP

// SYSTEM INCLUDES
#include <cstdint>
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/base/types/JointType.hpp>
#include <al5d_cpp/base/types/JointTypeDegrees.hpp>
#include <al5d_cpp/base/types/PulseWidth.hpp>
#include <al5d_cpp/base/types/PulseWidthRange.hpp>
#include <al5d_cpp/base/types/Degrees.hpp>
#include <al5d_cpp/base/types/DegreesRange.hpp>


namespace al5d
{
    typedef std::string Command;
    typedef std::string JointName;
    typedef unsigned int BoardChannel;
}


#endif // AL5D_CPP_TYPES_HPP
