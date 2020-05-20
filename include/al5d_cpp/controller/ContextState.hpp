#ifndef AL5D_CPP_CONTEXTSTATE_HPP
#define AL5D_CPP_CONTEXTSTATE_HPP

// SYSTEM INCLUDES
#include <string>
#include <memory>

// PROJECT INCLUDES
#include <al5d_cpp/controller/Controller.hpp>
#include <al5d_cpp/controller/ContextState.hpp>
#include <al5d_cpp/controller/events.hpp>


namespace al5d
{
    typedef al5d::Event Event;
    
    class ContextState : public al5d::State
    {
    public:

        void do_activity() override = 0;
    
        void handle_event(
            Event event)
            override;

    protected:

        ContextState(
            const std::string& state_name,
            Controller *context_ptr);
        
        void log_handling_event(
            const std::string &event_string)
            const;
    
        Controller* context_ptr;

    private:

        void on_halt_requested_event();
    };
    
    typedef std::shared_ptr<ContextState> ContextStatePtr;
}


#endif // AL5D_CPP_CONTEXTSTATE_HPP
