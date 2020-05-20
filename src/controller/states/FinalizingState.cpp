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
        , finalizing_started(false)
    {
    }


    void FinalizingState::do_activity()
    {
        start_finalizing_if_not_already();
        check_finalizing_progress_if_started();
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
    
    
    void FinalizingState::start_finalizing_if_not_already()
    {
        if (!finalizing_started)
        {
            log_doing_action("START_FINILIZING");
            context_ptr->start_finalizing();
            finalizing_started = true;
        }
    }
    
    
    void FinalizingState::check_finalizing_progress_if_started()
    {
        if (finalizing_started)
        {
            context_ptr->check_finalizing_progress();
        }
    }
    
    
    void FinalizingState::on_finalizing_finished_event()
    {
        log_handling_event("EVENT_FINALIZING_FINISHED");
        context_ptr->stop_running();
    }
}
