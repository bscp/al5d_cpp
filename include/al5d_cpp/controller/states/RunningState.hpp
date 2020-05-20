#ifndef AL5D_CPP_RUNNINGSTATE_HPP
#define AL5D_CPP_RUNNINGSTATE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/ContextState.hpp>


namespace al5d_cpp
{
    class RunningState : public ContextState
    {
    public:
        virtual ~RunningState() = default;
    
        void do_activity() override = 0;
        
        void handle_event(
            Event event)
            override;

    protected:

        RunningState(
            const std::string& state_name,
            Controller* context_ptr);
        
    private:

        void on_shutdown_requested_event();
    };
}

#endif // AL5D_CPP_RUNNINGSTATE_HPP
