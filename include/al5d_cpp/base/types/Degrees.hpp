#ifndef AL5D_CPP_DEGREES_HPP
#define AL5D_CPP_DEGREES_HPP

// SYSTEM INCLUDES
#include <vector>

namespace al5d
{
    class Degrees // TODO : rename to Degree
    {
    public:

        typedef int Value;
        
        explicit Degrees(
            Value value);

        virtual ~Degrees() = default;
        
        Value value;
        
    private:

        void validate(
            Value value)
            const;
    };

    // typedef std::vector<Degree> Degrees; // TODO : uncomment
}


#endif // AL5D_CPP_DEGREES_HPP
