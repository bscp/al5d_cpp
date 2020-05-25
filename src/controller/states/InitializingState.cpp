
// HEADER INCLUDE
#include <al5d_cpp/controller/states/InitializingState.hpp>


namespace al5d_cpp
{
    /*static*/ ContextStatePtr InitializingState::as_pointer(
        Controller* context_ptr)
    {
        return std::make_shared<InitializingState>(context_ptr);
    }


    InitializingState::InitializingState(
        Controller* context_ptr)
        : ContextState("InitializingState", context_ptr)
    {
    }


    void InitializingState::enter()
    {
        log_doing_action("ENTERING :: START_INITIALIZING");
        context_ptr->start_initializing();
    }


    void InitializingState::do_activity()
    {
        context_ptr->check_initializing_progress();
    }


    void InitializingState::handle_event(Event event)
    {
        switch (event)
        {
        case EVENT_INITIALIZING_FINISHED:
            return on_initializing_finished_event();
            
        default:
            return ContextState::handle_event(event);
        }
    }
    
    
    void InitializingState::on_initializing_finished_event()
    {
        log_handling_event("INITIALIZING_FINISHED");
        context_ptr->change_to_idling_state();
    }
}
