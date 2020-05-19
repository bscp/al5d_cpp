#ifndef SRC_IDLINGSTATE_HPP
#define SRC_IDLINGSTATE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/ContextState.hpp>


namespace al5d
{
    class IdlingState : public ContextState
    {
    public:
        static ContextStatePtr as_pointer(
            Controller *context_ptr);
        
        explicit IdlingState(
            Controller *context_ptr);

        virtual ~IdlingState() = default;
    
        void do_activity() override;
    
        void handle_event(Event event) override;
        
    private:
        void on_new_command_planned_event();
        void on_shutdown_requested_event();
    };
}

#endif // SRC_IDLINGSTATE_HPP
