// HEADER INCLUDE
#include <al5d_cpp/controller/states/HaltingState.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/controller/events.hpp>


namespace al5d
{
    /*static*/ ContextStatePtr HaltingState::as_pointer(
        Controller *context_ptr)
    {
        return std::make_shared<HaltingState>(context_ptr);
    }


    HaltingState::HaltingState(
        Controller *context_ptr)
        : ContextState("HaltingState", context_ptr)
    {
    }
    
    
    void HaltingState::enter()
    {
        ContextState::enter();
        context_ptr->preempt_scheduled_commands();
    }
    
    
    void HaltingState::do_activity()
    {
        // only waiting for the EMERGENCY_CLEARED event
    }
    
    
    void HaltingState::handle_event(Event event)
    {
        switch (event)
        {
        case EVENT_EMERGENCY_CLEARED:
            return on_emergency_cleared_event();
            
        default:
            return ContextState::handle_event(event);
        }
    }
    
    
    void HaltingState::on_emergency_cleared_event()
    {
        log_handling_event("EMERGENCY_CLEARED");
        context_ptr->change_to_idling_state();
    }
}
