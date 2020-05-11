// HEADER INCLUDES
#include <al5d_cpp/base/types/DegreesRange.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions/InvalidDegreesRange.hpp>


namespace al5d
{
    // begin of private symbols

    
    namespace
    {
        Degrees get_lowest(
            Degrees::Value value_1,
            Degrees::Value value_2)
        {
            return value_1 <= value_2 ? Degrees(value_1) : Degrees(value_2);
        }


        Degrees get_highest(
            Degrees::Value value_1,
            Degrees::Value value_2)
        {
            return value_1 <= value_2 ? Degrees(value_2) : Degrees(value_1);
        }
    }


    // end of private symbols


    DegreesRange::DegreesRange(
        const Degrees& value_1,
        const Degrees& value_2)
        : value_1(value_1)
        , value_2(value_2)
        , min(get_lowest(value_1.value, value_2.value))
        , max(get_highest(value_1.value, value_2.value))
    {
        validate();
    }

    void DegreesRange::validate()
        const
    {
        if (min.value >= max.value)
        {
            throw InvalidDegreesRange();
        }
    }
    

    bool DegreesRange::is_within_range(
        const Degrees& degrees)
        const
    {
        bool above_lower_bound = min.value <= degrees.value;
        bool below_upper_bound = degrees.value <= max.value;
        return above_lower_bound && below_upper_bound;
    }
    

    double DegreesRange::get_difference()
        const
    {
        return max.value - min.value;
    }
}
