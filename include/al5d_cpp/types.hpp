
#ifndef AL5D_CPP_TYPES_HPP
#define AL5D_CPP_TYPES_HPP

// SYSTEM INCLUDES
#include <cstdint>

namespace al5d
{
    typedef uint16_t PulseWidth; // TODO : limit to 0 to 2500 : make indistinguishable type
    typedef uint8_t BoardChannel; // TODO : validate if in range of ssc32u channels
    typedef int16_t Degrees; // TODO : limit to -360 to 360
}

#endif // AL5D_CPP_TYPES_HPP
