// HEADER INCLUDES
#include <al5d_cpp/base/types/DegreeRange.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions.hpp>


namespace al5d
{
    // begin of private symbols

    
    namespace
    {
        Degree get_lowest(
            Degree::Value value_1,
            Degree::Value value_2)
        {
            return value_1 <= value_2 ? Degree(value_1) : Degree(value_2);
        }


        Degree get_highest(
            Degree::Value value_1,
            Degree::Value value_2)
        {
            return value_1 <= value_2 ? Degree(value_2) : Degree(value_1);
        }
    }


    // end of private symbols


    DegreeRange::DegreeRange(
        const Degree& value_1,
        const Degree& value_2)
        : value_1(value_1)
        , value_2(value_2)
        , min(get_lowest(value_1.value, value_2.value))
        , max(get_highest(value_1.value, value_2.value))
    {
        validate();
    }


    DegreeRange::DegreeRange(
        const Degree::Value& value_1,
        const Degree::Value& value_2)
        : DegreeRange(Degree(value_1), Degree(value_2))
    {
    }


    void DegreeRange::validate()
        const
    {
        if (min.value >= max.value)
        {
            throw InvalidDegreeRange();
        }
    }
    

    bool DegreeRange::is_within_range(
        const Degree& degrees)
        const
    {
        bool above_lower_bound = min.value <= degrees.value;
        bool below_upper_bound = degrees.value <= max.value;
        return above_lower_bound && below_upper_bound;
    }
    

    double DegreeRange::get_difference()
        const
    {
        return max.value - min.value;
    }
}
