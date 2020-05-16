// HEADER INCLUDES
#include <al5d_cpp/base/types/PulseWidthRange.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions.hpp>


namespace al5d
{
    PulseWidthRange::PulseWidthRange(
        const PulseWidth& min,
        const PulseWidth& max)
        : min(min)
        , max(max)
    {
        validate();
    }
    

    void PulseWidthRange::validate()
        const
    {
        if (min.value >= max.value)
        {
            throw InvalidPulseWidthRange();
        }
    }
    

    double PulseWidthRange::get_difference()
        const
    {
        return max.value - min.value;
    }
}
