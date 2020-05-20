
// HEADER INCLUDE
#include <al5d_cpp/controller/states/InitializingState.hpp>


namespace al5d
{
    /*static*/ ContextStatePtr InitializingState::as_pointer(
        Controller* context_ptr)
    {
        return std::make_shared<InitializingState>(context_ptr);
    }


    InitializingState::InitializingState(
        Controller* context_ptr)
        : ContextState("InitializingState", context_ptr)
        , initializing_started(false)
    {
    }


    void InitializingState::do_activity()
    {
        start_initializing_if_not_already();
        check_initializing_progress_if_started();
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
    
    
    void InitializingState::start_initializing_if_not_already()
    {
        if (!initializing_started)
        {
            log_doing_action("START_INITIALIZING");
            context_ptr->start_initializing();
            initializing_started = true;
        }
    }
    
    
    void InitializingState::check_initializing_progress_if_started()
    {
        if (initializing_started)
        {
            context_ptr->check_initializing_progress();
        }
    }
    
    
    void InitializingState::on_initializing_finished_event()
    {
        log_handling_event("INITIALIZING_FINISHED");
        context_ptr->change_to_idling_state();
    }
}
