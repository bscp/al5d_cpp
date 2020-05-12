// HEADER INCLUDE
#include <al5d_cpp/exceptions/InvalidDegree.hpp>

#define MESSAGE "Invalid degree given"


namespace al5d
{
    InvalidDegree::InvalidDegree()
        : runtime_error(MESSAGE)
    {
    }
}
