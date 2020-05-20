// HEADER INCLUDES
#include <al5d_cpp/base/types/PulseWidth.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions.hpp>

namespace al5d_cpp
{
    PulseWidth::PulseWidth(
        Value value)
        : value(value)
    {
        validate();
    }


    void PulseWidth::validate()
        const
    {
        // PulseWidth is an unsigned type and thus always larger then zero
        if (value > Value(10000))
        {
            throw InvalidPulseWidth();
        }
    }
}
