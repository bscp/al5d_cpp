#ifndef AL5D_CPP_DEGREE_HPP
#define AL5D_CPP_DEGREE_HPP


namespace al5d_cpp
{
    class Degree
    {
    public:

        typedef int Value;
        
        explicit Degree(
            Value value);

        virtual ~Degree() = default;
        
        Value value;
        
    private:

        void validate()
            const;
    };
}


#endif // AL5D_CPP_DEGREE_HPP
