#ifndef AL5D_CPP_PULSEWIDTHRANGE_HPP
#define AL5D_CPP_PULSEWIDTHRANGE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/types/PulseWidth.hpp>


namespace al5d_cpp
{
    struct PulseWidthRange
    {
        const PulseWidth min;
        const PulseWidth max;
        
        PulseWidthRange(
            const PulseWidth& min,
            const PulseWidth& max);

        PulseWidthRange(
            const PulseWidth::Value& min,
            const PulseWidth::Value& max);

        double get_difference()
            const;

    private:

        void validate()
            const;
    };
}


#endif // AL5D_CPP_PULSEWIDTHRANGE_HPP
