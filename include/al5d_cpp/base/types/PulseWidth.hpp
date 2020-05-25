#ifndef AL5D_CPP_PULSEWIDTH_HPP
#define AL5D_CPP_PULSEWIDTH_HPP


namespace al5d_cpp
{
    struct PulseWidth
    {
        typedef unsigned int Value;
        
        Value value;

        explicit PulseWidth(
            Value value);
        
    private:

        void validate()
            const;
    };
}


#endif // AL5D_CPP_PULSEWIDTH_HPP
