#ifndef AL5D_CPP_PULSEWIDTH_HPP
#define AL5D_CPP_PULSEWIDTH_HPP


namespace al5d
{
    class PulseWidth
    {
    public:

        typedef unsigned int Value;
        
        explicit PulseWidth(
            Value value);

        virtual ~PulseWidth() = default;
        
        Value value;
        
    private:

        void validate(
            Value value)
            const;
    };
}


#endif // AL5D_CPP_PULSEWIDTH_HPP
