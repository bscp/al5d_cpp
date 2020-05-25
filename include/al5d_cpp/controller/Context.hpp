#ifndef AL5D_CPP_CONTEXT_HPP
#define AL5D_CPP_CONTEXT_HPP

// SYSTEM INCLUDES
#include <queue>
#include <algorithm>

// PROJECT INCLUDES
#include <al5d_cpp/controller/State.hpp>
#include <al5d_cpp/logging.hpp>


namespace al5d_cpp
{
    class Context
    {
    public:
    
        Context();
        
        void run_once();
        
        void stop_running();
        
        void start_running();
        
        virtual void set_start_state() = 0;
        
        void change_state(const StatePtr &new_state_ptr);
        
        void schedule_event(Event event);
        
        void preempt_events();
        
        template<typename StateType>
        bool is_current_state() const;

        bool get_is_running() const;

    private:

        void handle_all_events();
        
        void log_state_change(
            const StatePtr &new_state_ptr)
            const;
        
        StatePtr current_state_ptr;
        std::queue<Event> events;
        bool is_running;
    };
    
    template <typename StateType> bool Context::is_current_state() const
    {
        return std::dynamic_pointer_cast<StateType>(current_state_ptr) != nullptr;
    }
}


#endif // AL5D_CPP_CONTEXT_HPP