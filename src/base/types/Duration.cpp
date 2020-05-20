// HEADER INCLUDES
#include <al5d_cpp/base/types/Duration.hpp>


namespace al5d
{
    /*static*/ Duration Duration::from_milliseconds(Milliseconds milliseconds)
    {
        return Duration(milliseconds);
    }
    
    
    /*static*/ Duration Duration::from_seconds(Seconds seconds)
    {
        auto milliseconds = Milliseconds(seconds * 1000);
        return Duration(milliseconds);
    }


    /*static*/ Duration Duration::from_ms(Milliseconds milliseconds)
    {
        return Duration::from_milliseconds(milliseconds);
    }
    
    
    /*static*/ Duration Duration::from_s(Seconds seconds)
    {
        return Duration::from_seconds(seconds);
    }
    
    
    Duration::Duration(Milliseconds milliseconds)
        : milliseconds(milliseconds)
    {
    }
    
    
    Duration::Seconds Duration::in_seconds() const
    {
        return Seconds(milliseconds) / 1000;
    }
    
    
    Duration::Milliseconds Duration::in_milliseconds() const
    {
        return milliseconds;
    }
}
