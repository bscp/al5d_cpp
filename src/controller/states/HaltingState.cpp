// TODO : add ConnectingState because SerialCommunicator does not connect instantly

// HEADER INCLUDE
#include <al5d_cpp/controller/states/HaltingState.hpp>


namespace al5d_cpp
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
    }
    
    
    void HaltingState::do_activity()
    {
        // only waiting for the UNHALT_COMMAND_RECEIVED event
    }
    
    
    void HaltingState::handle_event(Event event)
    {
        switch (event)
        {
        case UNHALT_COMMAND_RECEIVED:
            return on_unhalt_command_received();
            
        default:
            return ContextState::handle_event(event);
        }
    }
    
    
    void HaltingState::on_unhalt_command_received()
    {
        log_handling_event("EMERGENCY_CLEARED");
        context_ptr->change_to_idling_state();
    }
}
