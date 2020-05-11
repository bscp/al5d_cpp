#ifndef SRC_INVALIDPULSEWIDTH_HPP
#define SRC_INVALIDPULSEWIDTH_HPP

// SYSTEM INCLUDES
#include <stdexcept>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    class InvalidPulseWidth : public std::runtime_error
    {
    public:
        InvalidPulseWidth();
    };
}


#endif // SRC_INVALIDPULSEWIDTH_HPP
