#ifndef AL5D_CPP_PULSEWIDTHRANGE_HPP
#define AL5D_CPP_PULSEWIDTHRANGE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/types/PulseWidth.hpp>


namespace al5d
{
    class PulseWidthRange
    {   
    public:

        PulseWidthRange(
            const PulseWidth& min,
            const PulseWidth& max);

        virtual ~PulseWidthRange() = default;

        double get_difference()
            const;

        const PulseWidth min;
        const PulseWidth max;

    private:

        void validate()
            const;
    };
}


#endif // AL5D_CPP_PULSEWIDTHRANGE_HPP
