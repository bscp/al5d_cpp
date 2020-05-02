// HEADER INCLUDES
#include <al5d_cpp/Duration.hpp>


namespace al5d
{
    Duration Duration::from_milliseconds(Milliseconds milliseconds)
    {
        return Duration(milliseconds);
    }
    
    
    Duration Duration::from_seconds(Seconds seconds)
    {
        auto milliseconds = Milliseconds(seconds * 1000);
        return Duration(milliseconds);
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
