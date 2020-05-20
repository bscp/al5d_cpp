#ifndef AL5D_CPP_DEGREERANGE_HPP
#define AL5D_CPP_DEGREERANGE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/types/Degree.hpp>


namespace al5d_cpp
{
    class DegreeRange
    {
    public:

        DegreeRange(
            const Degree& value_1,
            const Degree& value_2);

        DegreeRange(
            const Degree::Value& value_1,
            const Degree::Value& value_2);

        virtual ~DegreeRange() = default;

        bool is_within_range(
            const Degree& degrees)
            const;

        double get_difference()
            const;

        const Degree value_1;
        const Degree value_2;

        const Degree min;
        const Degree max;

    private:

        void validate()
            const;
    };
}


#endif // AL5D_CPP_DEGREERANGE_HPP
