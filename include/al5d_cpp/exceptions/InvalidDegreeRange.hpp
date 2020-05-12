#ifndef SRC_INVALIDDEGREERANGE_HPP
#define SRC_INVALIDDEGREERANGE_HPP

// SYSTEM INCLUDES
#include <stdexcept>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    class InvalidDegreeRange : public std::runtime_error
    {
    public:
        InvalidDegreeRange();
    };
}


#endif // SRC_INVALIDDEGREERANGE_HPP
