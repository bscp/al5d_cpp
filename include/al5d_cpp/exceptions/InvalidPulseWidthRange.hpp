#ifndef SRC_INVALIDPULSEWIDTHRANGE_HPP
#define SRC_INVALIDPULSEWIDTHRANGE_HPP

// SYSTEM INCLUDES
#include <stdexcept>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    class InvalidPulseWidthRange : public std::runtime_error
    {
    public:
        InvalidPulseWidthRange();
    };
}


#endif // SRC_INVALIDPULSEWIDTHRANGE_HPP
