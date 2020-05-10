#ifndef SRC_INVALIDDEGREES_HPP
#define SRC_INVALIDDEGREES_HPP

// SYSTEM INCLUDES
#include <stdexcept>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    class InvalidDegrees : public std::runtime_error
    {
    public:
        explicit InvalidDegrees(
            const Degrees& degrees);
    };
}


#endif // SRC_INVALIDDEGREES_HPP