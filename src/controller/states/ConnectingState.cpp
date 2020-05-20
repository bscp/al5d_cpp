// HEADER INCLUDE
#include <al5d_cpp/controller/states/ConnectingState.hpp>


namespace al5d_cpp
{
    /*static*/ ContextStatePtr ConnectingState::as_pointer(
        Controller* context_ptr)
    {
        return std::make_shared<ConnectingState>(context_ptr);
    }


    ConnectingState::ConnectingState(
        Controller* context_ptr)
        : ContextState("ConnectingState", context_ptr)
    {
    }


    void ConnectingState::do_activity()
    {
        // Connecting progress is started from AL5DBase constructor
        check_connecting_progress();
    }


    void ConnectingState::handle_event(Event event)
    {
        switch (event)
        {
        case EVENT_CONNECTING_FINISHED:
            return on_connecting_finished_event();
            
        default:
            return ContextState::handle_event(event);
        }
    }
    
    
    void ConnectingState::check_connecting_progress()
    {
        context_ptr->check_connecting_progress();
    }
    
    
    void ConnectingState::on_connecting_finished_event()
    {
        log_handling_event("CONNECTING_FINISHED");
        context_ptr->change_to_initializing_state();
    }
}
