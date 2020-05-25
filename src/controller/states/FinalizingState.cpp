// HEADER INCLUDE
#include <al5d_cpp/controller/states/FinalizingState.hpp>


namespace al5d_cpp
{
    /*static*/ ContextStatePtr FinalizingState::as_pointer(
        Controller* context_ptr)
    {
        return std::make_shared<FinalizingState>(context_ptr);
    }


    FinalizingState::FinalizingState(
        Controller* context_ptr)
        : ContextState("FinalizingState", context_ptr)
    {
    }


    void FinalizingState::enter()
    {
        log_doing_action("ENTERING :: START_FINILIZING");
        context_ptr->start_finalizing();
    }


    void FinalizingState::do_activity()
    {
        context_ptr->check_finalizing_progress();
    }


    void FinalizingState::handle_event(Event event)
    {
        switch (event)
        {
        case EVENT_FINALIZING_FINISHED:
            return on_finalizing_finished_event();
            
        default:
            return ContextState::handle_event(event);
        }
    }
    
    
    void FinalizingState::on_finalizing_finished_event()
    {
        log_handling_event("EVENT_FINALIZING_FINISHED");
        context_ptr->stop_running();
    }
}
