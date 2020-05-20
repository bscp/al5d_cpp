
#ifndef AL5D_CPP_STATE_HPP
#define AL5D_CPP_STATE_HPP

// SYSTEM INCLUDES
#include <memory>

namespace al5d
{
    typedef int Event;
    
    class State
    {
    public:
        virtual void enter();
        
        virtual void do_activity() = 0;
    
        virtual void exit();
    
        virtual void handle_event(
            Event event) = 0;

        const std::string &get_name()
            const;

    protected:
        explicit State(
            std::string state_name);
    
        void log_doing_action(
            const std::string& action)
            const;
        
        void log_entering_action()
            const;
        
        void log_exiting_action()
            const;
        
        void log_action(
            const std::string &action)
            const;
        
        const std::string name;
    };
    
    typedef std::shared_ptr<State> StatePtr;
}

#endif // AL5D_CPP_STATE_HPP
