// HEADER INCLUDE
#include <al5d_cpp/controller/State.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>


namespace al5d
{
    State::State(std::string state_name)
        : name(std::move(state_name))
    {
    }
    
    
    void State::enter()
    {
        log_entering_action();
    }
    
    
    void State::exit()
    {
        log_exiting_action();
    }
    
    
    void State::log_exiting_action()
        const
    {
        log_action("EXITING");
    }
    
    
    void State::log_entering_action()
        const
    {
        log_action("ENTERING");
    }
    
    
    void State::log_doing_action(
        const std::string& action)
        const
    {
        log_action(name + " :: DOING :: " + action);
    }
    
    
    void State::log_action(
        const std::string& action)
        const
    {
        LOG_INFO(name + " :: " + action);
    }
    
    
    const std::string &State::get_name() const
    {
        return name;
    }
}
