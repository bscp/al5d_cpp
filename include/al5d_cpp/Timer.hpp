#ifndef AL5D_CPP_TIMER_HPP
#define AL5D_CPP_TIMER_HPP

// SYSTEM INCLUDES
#include <chrono>
#include <memory>


namespace al5d
{
    class Timer;
    typedef std::shared_ptr<Timer> TimerPtr;
    
    class Timer
    {
    private:
        typedef std::chrono::high_resolution_clock high_resolution_clock;
        typedef std::chrono::milliseconds milliseconds;

    public:
        static TimerPtr as_pointer(
            long duration);
        
        explicit Timer(long duration);

        Timer(const Timer& other) = default;

        bool has_elapsed() const;
        
    private:
        high_resolution_clock::time_point start_time;
        const long duration;
    };
}


#endif // AL5D_CPP_TIMER_HPP
