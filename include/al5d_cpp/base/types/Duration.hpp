#ifndef AL5D_CPP_DURATION_HPP
#define AL5D_CPP_DURATION_HPP


namespace al5d
{
    class Duration
    {
    private:
        using Milliseconds = long;
        using Seconds = double;
        
    public:
        static Duration from_milliseconds(
            Milliseconds milliseconds);
        
        static Duration from_seconds(
            Seconds seconds);

        static Duration from_ms(
            Milliseconds milliseconds);

        static Duration from_s(
            Seconds seconds);

        virtual ~Duration() = default;
        
        Seconds in_seconds() const;
    
        Milliseconds in_milliseconds() const;
        
    private:
        explicit Duration(
            Milliseconds milliseconds);

        Milliseconds milliseconds;
    };
}


#endif // AL5D_CPP_DURATION_HPP
