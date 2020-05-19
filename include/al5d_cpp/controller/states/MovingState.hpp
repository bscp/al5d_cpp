#ifndef SRC_MOVINGSTATE_HPP
#define SRC_MOVINGSTATE_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/ContextState.hpp>


namespace al5d
{
    class MovingState : public ContextState
    {
    public:
        static ContextStatePtr as_pointer(
            Controller *context_ptr);
        
        explicit MovingState(
            Controller *context_ptr);

        virtual ~MovingState() = default;
    
        void do_activity() override;
    
        void handle_event(Event event) override;

    private:
        void start_moving_if_not_already();
    
        void check_moving_progress_if_started();
    
        void on_moving_finished_event();
    
        bool moving_started;
    };
}

#endif // SRC_MOVINGSTATE_HPP
