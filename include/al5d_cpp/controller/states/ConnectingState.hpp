#ifndef AL5D_CPP_CONNECTINGSTATE_HPP
#define AL5D_CPP_CONNECTINGSTATE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/ContextState.hpp>


namespace al5d_cpp
{
    class ConnectingState : public ContextState
    {
    public:
        static ContextStatePtr as_pointer(
            Controller* context_ptr);
        
        explicit ConnectingState(
            Controller* context_ptr);

        void do_activity() override;
    
        void handle_event(Event event) override;

    private:
    
        void on_connecting_finished_event();
    };
}

#endif // AL5D_CPP_CONNECTINGSTATE_HPP
