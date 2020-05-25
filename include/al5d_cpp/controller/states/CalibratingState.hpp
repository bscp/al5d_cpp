#ifndef AL5D_CPP_CALIBRATINGSTATE_HPP
#define AL5D_CPP_CALIBRATINGSTATE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/ContextState.hpp>


namespace al5d_cpp
{
    class CalibratingState : public ContextState
    {
    public:
        static ContextStatePtr as_pointer(
            Controller *context_ptr);
        
        explicit CalibratingState(
            Controller *context_ptr);

        virtual ~CalibratingState() = default;

        void enter()
            override;

        void do_activity()
            override;
    
        void handle_event(Event event)
            override;

    private:
        
        void on_calibrating_finished_event();
    };
}

#endif // AL5D_CPP_CALIBRATINGSTATE_HPP
