// HEADER INCLUDE
#include <al5d_cpp/controller/states/IdlingState.hpp>


namespace al5d_cpp
{
    /*static*/ ContextStatePtr IdlingState::as_pointer(
        Controller *context_ptr)
    {
        return std::make_shared<IdlingState>(context_ptr);
    }
    
    
    IdlingState::IdlingState(
        Controller *context_ptr)
        : RunningState("IdlingState", context_ptr)
    {
    }
    
    
    void IdlingState::do_activity()
    {
        context_ptr->schedule_next_command_if_available();
    }
    
    
    void IdlingState::handle_event(Event event)
    {
        switch (event)
        {
        case EVENT_NEW_COMMAND_PLANNED:
            return on_new_command_planned_event();
        
        default:
            return RunningState::handle_event(event);
        }
    }
    
    
    void IdlingState::on_new_command_planned_event()
    {
        log_handling_event("NEW_COMMAND_PLANNED");
        context_ptr->change_to_moving_state();
    }
}
