// HEADER INCLUDES
#include <al5d_cpp/base/types/Degrees.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions/InvalidDegrees.hpp>


namespace al5d
{
    Degrees::Degrees(
        Value value)
        : value(value)
    {
        validate(value);
    }


    void Degrees::validate(
        Value value)
        const
    {
        if (value < -360)
        {
            throw InvalidDegrees();
        }
        if (value > 360)
        {
            throw InvalidDegrees();
        }
    }
}
