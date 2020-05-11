#ifndef SRC_INVALIDDEGREESRANGE_HPP
#define SRC_INVALIDDEGREESRANGE_HPP

// SYSTEM INCLUDES
#include <stdexcept>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    class InvalidDegreesRange : public std::runtime_error
    {
    public:
        InvalidDegreesRange();
    };
}


#endif // SRC_INVALIDDEGREESRANGE_HPP
