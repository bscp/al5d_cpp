#ifndef AL5D_CPP_FINALIZINGSTATE_HPP
#define AL5D_CPP_FINALIZINGSTATE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/ContextState.hpp>


namespace al5d_cpp
{
    class FinalizingState : public ContextState
    {
    public:
        static ContextStatePtr as_pointer(
            Controller *context_ptr);
        
        explicit FinalizingState(
            Controller *context_ptr);

        void enter()
            override;
            
        void do_activity()
            override;
    
        void handle_event(Event event)
            override;

    private:
        
        void on_finalizing_finished_event();
    };
}

#endif // AL5D_CPP_FINALIZINGSTATE_HPP
