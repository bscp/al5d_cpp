// HEADER INCLUDE
#include <al5d_cpp/exceptions/InvalidPulseWidthRange.hpp>

#define MESSAGE "Invalid pulse_width_range in config"


namespace al5d
{
    InvalidPulseWidthRange::InvalidPulseWidthRange()
        : runtime_error(MESSAGE)
    {
    }
}
