#ifndef SRC_HALTINGSTATE_HPP
#define SRC_HALTINGSTATE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/ContextState.hpp>


namespace al5d
{
    class HaltingState : public ContextState
    {
    public:
        static ContextStatePtr as_pointer(
            Controller *context_ptr);
        
        explicit HaltingState(
            Controller *context_ptr);

        virtual ~HaltingState() = default;
    
        void enter() override;
        
        void do_activity() override;
    
        void handle_event(Event event) override;

    private:
        void on_emergency_cleared_event();
    };
}

#endif // SRC_HALTINGSTATE_HPP
