#ifndef AL5D_CPP_IDLINGSTATE_HPP
#define AL5D_CPP_IDLINGSTATE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/states/RunningState.hpp>


namespace al5d_cpp
{
    class IdlingState : public RunningState
    {
    public:
        static ContextStatePtr as_pointer(
            Controller *context_ptr);
        
        explicit IdlingState(
            Controller *context_ptr);

        void do_activity() override;
    
        void handle_event(Event event) override;
        
    private:
    
        void on_new_command_planned_event();
    };
}

#endif // AL5D_CPP_IDLINGSTATE_HPP
