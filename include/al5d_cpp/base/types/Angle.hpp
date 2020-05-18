#ifndef AL5D_CPP_ANGLE_HPP
#define AL5D_CPP_ANGLE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/types/Degree.hpp>


namespace al5d
{
    class Angle
    {
    private:

        typedef Degree Value;

    public:
        
        static Angle from_degree(
            const Degree& degree);
        
        static Angle from_degree(
            const Degree::Value& degree_value);

        virtual ~Angle() = default;

        Degree in_degree()
            const;
        
    private:

        explicit Angle(
            const Value& value);

        const Value value;
    };
}


#endif // AL5D_CPP_ANGLE_HPP
