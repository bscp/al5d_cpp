// HEADER INCLUDE
#include <al5d_cpp/exceptions/InvalidDegreesRange.hpp>

#define MESSAGE "Invalid degrees_range in config"


namespace al5d
{
    InvalidDegreesRange::InvalidDegreesRange()
        : runtime_error(MESSAGE)
    {
    }
}
