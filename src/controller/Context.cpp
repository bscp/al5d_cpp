
// HEADER INCLUDE
#include <al5d_cpp/controller/Context.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>


namespace al5d
{
    Context::Context()
        : current_state_ptr(nullptr)
        , events()
        , is_running(true)
    {
    }
    
    
    void Context::change_state(const StatePtr &new_state_ptr)
    {
        if (current_state_ptr != nullptr)
        {
            current_state_ptr->exit();
            log_state_change(new_state_ptr);
        }
        
        current_state_ptr = new_state_ptr;
        current_state_ptr->enter();
    }
    
    
    void Context::schedule_event(Event event)
    {
        events.push(event);
    }
    
    
    void Context::run_once()
    {
        current_state_ptr->do_activity();
        handle_all_events();
    }
    
    
    void Context::handle_all_events()
    {
        while (!events.empty())
        {
            Event event = events.front();
            current_state_ptr->handle_event(event);
            events.pop();
        }
    }
    
    
    void Context::start_running()
    {
        is_running = true;
    }
    
    
    void Context::stop_running()
    {
        is_running = false;
    }
    
    
    void Context::preempt_events()
    {
        std::queue<Event> new_events;
        std::swap(events, new_events);
    }
    
    
    void Context::log_state_change(
        const StatePtr &new_state_ptr)
        const
    {
        const auto& old_state_name = current_state_ptr->get_name();
        const auto& new_state_name = new_state_ptr->get_name();
        LOG_INFO("CHANGING_STATE :: " + old_state_name + " -> " + new_state_name);
    }
    
    
    bool Context::get_is_running() const
    {
        return is_running;
    }
}