// HEADER INCLUDES
#include <al5d_cpp/base/types/Degree.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions.hpp>


namespace al5d_cpp
{
    /*static*/ Angle Angle::from_degree(
        const Degree& degree)
    {
        return Angle(degree);
    }


    /*static*/ Angle Angle::from_degree(
        const Degree::Value& degree_value)
    {
        const Degree degree(degree_value);
        return Angle::from_degree(degree);
    }
    
    
    Angle::Angle(
        const Value& value)
        : value(value)
    {
    }


    Degree Angle::in_degree()
        const
    {
        return value;
    }
}
