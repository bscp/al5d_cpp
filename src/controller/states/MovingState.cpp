// HEADER INCLUDE
#include <al5d_cpp/controller/states/MovingState.hpp>


namespace al5d_cpp
{
    /*static*/ ContextStatePtr MovingState::as_pointer(
        Controller *context_ptr)
    {
        return std::make_shared<MovingState>(context_ptr);
    }
    
    
    MovingState::MovingState(
        Controller *context_ptr)
        : RunningState("MovingState", context_ptr)
    {
    }
    
    
    void MovingState::enter()
    {
        log_doing_action("ENTERING :: START_MOVING ");
        context_ptr->start_next_command();
    }


    void MovingState::do_activity()
    {
        context_ptr->check_moving_progress();
    }
    
    
    void MovingState::handle_event(Event event)
    {
        switch (event)
        {
        case EVENT_MOVING_FINISHED:
            return on_moving_finished_event();
    
        default:
            return RunningState::handle_event(event);
        }
    }
    
    
    void MovingState::on_moving_finished_event()
    {
        log_handling_event("MOVING_FINISHED");
        context_ptr->change_to_idling_state();
    }
}
