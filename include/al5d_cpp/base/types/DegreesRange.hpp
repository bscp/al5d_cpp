#ifndef AL5D_CPP_DEGREESRANGE_HPP
#define AL5D_CPP_DEGREESRANGE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/types/Degrees.hpp>


namespace al5d
{
    class DegreesRange
    {   
    public:

        DegreesRange(
            const Degrees& value_1,
            const Degrees& value_2);

        virtual ~DegreesRange() = default;

        bool is_within_range(
            const Degrees& degrees)
            const;

        double get_difference()
            const;

        const Degrees value_1;
        const Degrees value_2;

        const Degrees min;
        const Degrees max;

    private:

        void validate()
            const;
    };
}


#endif // AL5D_CPP_DEGREESRANGE_HPP
