
// HEADER INCLUDE
#include <al5d_cpp/controller/states/CalibratingState.hpp>


namespace al5d_cpp
{
    /*static*/ ContextStatePtr CalibratingState::as_pointer(
        Controller* context_ptr)
    {
        return std::make_shared<CalibratingState>(context_ptr);
    }


    CalibratingState::CalibratingState(
        Controller* context_ptr)
        : ContextState("CalibratingState", context_ptr)
        , calibrating_started(false)
    {
    }


    void CalibratingState::do_activity()
    {
        start_calibrating_if_not_already();
        check_calibrating_progress_if_started();
    }


    void CalibratingState::handle_event(Event event)
    {
        switch (event)
        {
        case EVENT_CALIBRATING_FINISHED:
            return on_calibrating_finished_event();
            
        default:
            return ContextState::handle_event(event);
        }
    }
    
    
    void CalibratingState::start_calibrating_if_not_already()
    {
        if (!calibrating_started)
        {
            log_doing_action("START_CALIBRATING");
            context_ptr->start_calibrating();
            calibrating_started = true;
        }
    }
    
    
    void CalibratingState::check_calibrating_progress_if_started()
    {
        if (calibrating_started)
        {
            context_ptr->check_calibrating_progress();
        }
    }
    
    
    void CalibratingState::on_calibrating_finished_event()
    {
        log_handling_event("CALIBRATING_FINISHED");
        context_ptr->change_to_initializing_state();
    }
}
