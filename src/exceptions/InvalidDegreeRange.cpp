// HEADER INCLUDE
#include <al5d_cpp/exceptions/InvalidDegreeRange.hpp>

#define MESSAGE "Invalid DegreeRange"


namespace al5d
{
    InvalidDegreeRange::InvalidDegreeRange()
        : runtime_error(MESSAGE)
    {
    }
}
