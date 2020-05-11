#ifndef AL5D_CPP_TYPES_HPP
#define AL5D_CPP_TYPES_HPP

// SYSTEM INCLUDES
#include <cstdint>
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/base/types/JointType.hpp>
#include <al5d_cpp/base/types/JointAngle.hpp>
#include <al5d_cpp/base/types/JointTypeAngle.hpp>


namespace al5d
{
    typedef std::string Command;
    typedef std::string JointName;
    typedef unsigned int PulseWidth;
    typedef unsigned int BoardChannel;
    typedef int Degrees;
}


#endif // AL5D_CPP_TYPES_HPP
