#ifndef AL5D_CPP_DEGREES_HPP
#define AL5D_CPP_DEGREES_HPP


namespace al5d
{
    class Degrees
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
}


#endif // AL5D_CPP_DEGREES_HPP
