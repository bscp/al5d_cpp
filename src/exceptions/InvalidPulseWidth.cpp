// HEADER INCLUDE
#include <al5d_cpp/exceptions/InvalidPulseWidth.hpp>

#define MESSAGE "Invalid pulse width in config"


namespace al5d
{
    InvalidPulseWidth::InvalidPulseWidth()
        : runtime_error(MESSAGE)
    {
    }
}
