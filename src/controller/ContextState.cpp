// HEADER INCLUDE
#include <al5d_cpp/controller/ContextState.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/controller/events.hpp>
#include <al5d_cpp/logging.hpp>


namespace al5d
{
    ContextState::ContextState(
        const std::string &state_name,
        Controller* context_ptr)
        : State(state_name)
        , context_ptr(context_ptr)
    {
    }
    
    
    void ContextState::handle_event(Event event)
    {
        LOG_WARNING("Unhandled event '" + std::to_string(event) + "'");
    }
    
    
    void ContextState::log_handling_event(
        const std::string&event_string)
        const
    {
        LOG_INFO(name + " :: HANDLING_EVENT :: Event='" + event_string + "'");
    }
}
