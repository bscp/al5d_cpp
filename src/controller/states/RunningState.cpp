// HEADER INCLUDE
#include <al5d_cpp/controller/states/RunningState.hpp>


namespace al5d
{
    RunningState::RunningState(
        const std::string &state_name,
        Controller* context_ptr)
        : ContextState(state_name, context_ptr)
    {
    }
    
    
    void RunningState::handle_event(Event event)
    {
        switch (event)
        {
        case EVENT_SHUTDOWN_REQUESTED:
            return on_shutdown_requested_event();
            
        default:
            return ContextState::handle_event(event);
        }
    }
    
    
    void RunningState::on_shutdown_requested_event()
    {
        log_handling_event("SHUTDOWN_REQUESTED");
        context_ptr->change_to_finalizing_state();
    }
}
