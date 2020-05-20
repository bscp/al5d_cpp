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

        virtual ~FinalizingState() = default;
        
        void do_activity()
            override;
    
        void handle_event(Event event)
            override;

    private:
        void start_finalizing_if_not_already();
    
        void check_finalizing_progress_if_started();
        
        void on_finalizing_finished_event();
        
        bool finalizing_started;
    };
}

#endif // AL5D_CPP_FINALIZINGSTATE_HPP
