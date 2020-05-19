// HEADER INCLUDE
#include <al5d_cpp/controller/states/MovingState.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/controller/events.hpp>


namespace al5d
{
    /*static*/ ContextStatePtr MovingState::as_pointer(
        Controller *context_ptr)
    {
        return std::make_shared<MovingState>(context_ptr);
    }
    
    
    MovingState::MovingState(
        Controller *context_ptr)
        : ContextState("MovingState", context_ptr)
        , moving_started(false)
    {
    }
    
    
    void MovingState::do_activity()
    {
        start_moving_if_not_already();
        check_moving_progress_if_started();
    }
    
    
    void MovingState::handle_event(Event event)
    {
        switch (event)
        {
        case EVENT_MOVING_FINISHED:
            return on_moving_finished_event();
    
        default:
            return ContextState::handle_event(event);
        }
    }
    
    
    void MovingState::start_moving_if_not_already()
    {
        if (!moving_started)
        {
            log_doing_action("START_MOVING ");
            context_ptr->start_next_command();
            moving_started = true;
        }
    }
    
    
    void MovingState::check_moving_progress_if_started()
    {
        if (moving_started)
        {
            context_ptr->check_moving_progress();
        }
    }
    
    
    void MovingState::on_moving_finished_event()
    {
        log_handling_event("MOVING_FINISHED");
        context_ptr->change_to_idling_state();
    }
}
