// HEADER INCLUDE
#include <al5d_cpp/Timer.hpp>


namespace al5d_cpp
{
    TimerPtr Timer::as_pointer(
        long duration)
    {
        return std::make_shared<Timer>(duration);
    }
    
    
    Timer::Timer(long duration)
        : start_time(high_resolution_clock::now())
        , duration(duration)
    {
    }
    
    
    bool Timer::has_elapsed()
        const
    {
        const auto end_time = high_resolution_clock::now();
        long elapsed_time = std::chrono::duration_cast<milliseconds>(end_time - start_time).count();
        return elapsed_time >= duration;
    }
}
