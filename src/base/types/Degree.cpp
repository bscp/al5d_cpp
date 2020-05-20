// HEADER INCLUDES
#include <al5d_cpp/base/types/Degree.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions.hpp>


namespace al5d_cpp
{
    Degree::Degree(
        Value value)
        : value(value)
    {
        validate();
    }


    void Degree::validate()
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
