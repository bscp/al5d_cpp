// HEADER INCLUDES
#include <al5d_cpp/base/types/Degree.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions/InvalidDegree.hpp>


namespace al5d
{
    Degree::Degree(
        Value value)
        : value(value)
    {
        validate(value);
    }


    void Degree::validate(
        Value value)
        const
    {
        if (value < -360)
        {
            throw InvalidDegree();
        }
        if (value > 360)
        {
            throw InvalidDegree();
        }
    }
}
