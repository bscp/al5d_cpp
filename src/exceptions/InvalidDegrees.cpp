// HEADER INCLUDE
#include <al5d_cpp/exceptions/InvalidDegrees.hpp>

#define MESSAGE "Invalid degrees given: "


namespace al5d
{
    InvalidDegrees::InvalidDegrees()
        : runtime_error(MESSAGE)
    {
    }
}
