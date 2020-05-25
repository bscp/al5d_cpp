#ifndef AL5D_CPP_HALTINGSTATE_HPP
#define AL5D_CPP_HALTINGSTATE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/ContextState.hpp>


namespace al5d_cpp
{
    class HaltingState : public ContextState
    {
    public:
        static ContextStatePtr as_pointer(
            Controller *context_ptr);
        
        explicit HaltingState(
            Controller *context_ptr);

        void do_activity() override;
    
        void handle_event(Event event) override;

    private:
    
        void on_unhalt_command_received();
    };
}

#endif // AL5D_CPP_HALTINGSTATE_HPP
