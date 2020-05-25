#ifndef AL5D_CPP_MOVINGSTATE_HPP
#define AL5D_CPP_MOVINGSTATE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/states/RunningState.hpp>


namespace al5d_cpp
{
    class MovingState : public RunningState
    {
    public:
        static ContextStatePtr as_pointer(
            Controller *context_ptr);
        
        explicit MovingState(
            Controller *context_ptr);

        virtual ~MovingState() = default;

        void enter()
            override;
            
        void do_activity()
            override;
    
        void handle_event(Event event)
            override;

    private:

        void on_moving_finished_event();
    };
}

#endif // AL5D_CPP_MOVINGSTATE_HPP
