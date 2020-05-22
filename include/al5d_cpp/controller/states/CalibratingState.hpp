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
    
        void do_activity()
            override;
    
        void handle_event(Event event)
            override;

    private:
        void start_calibrating_if_not_already();
    
        void check_calibrating_progress_if_started();
        
        void on_calibrating_finished_event();
        
        bool calibrating_started;
    };
}

#endif // AL5D_CPP_CALIBRATINGSTATE_HPP
