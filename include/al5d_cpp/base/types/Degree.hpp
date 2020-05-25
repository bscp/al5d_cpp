#ifndef AL5D_CPP_DEGREE_HPP
#define AL5D_CPP_DEGREE_HPP


namespace al5d_cpp
{
    struct Degree
    {
        typedef int Value;

        Value value;
        
        explicit Degree(
            Value value);
        
    private:

        void validate()
            const;
    };
}


#endif // AL5D_CPP_DEGREE_HPP
