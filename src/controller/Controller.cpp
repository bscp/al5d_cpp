// HEADER INCLUDE
#include <al5d_cpp/controller/Controller.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/controller/events.hpp>
#include <al5d_cpp/controller/states.hpp>
#include <al5d_cpp/controller/commands.hpp>


namespace al5d
{
    Controller::Controller(
        const AL5DBase& al5d)
        : Context()
        , al5d(al5d)
    {
    }


    Controller::~Controller() // TODO : why needed?
    {
    }


    void Controller::set_start_state()
    {
        change_to_idling_state();
    }


    void Controller::schedule_pose_command(
        const PoseName& pose_name,
        const Duration& move_duration)
    {
        auto command_ptr = PoseCommand::as_ptr(this);
        scheduled_command_ptrs.push(command_ptr);
    }


    void Controller::change_to_idling_state()
    {
        change_state(IdlingState::as_pointer(this));
    }


    void Controller::change_to_moving_state()
    {
        change_state(MovingState::as_pointer(this));
    }


    void Controller::change_to_halting_state()
    {
        change_state(HaltingState::as_pointer(this));
    }


    void Controller::execute_pose_command()
    {
        // TODO : implement method
    }
    
    
    void Controller::schedule_next_command_if_available()
    {
        if (new_command_available())
        {
            schedule_next_command();
            schedule_event(EVENT_NEW_COMMAND_PLANNED);
        }
    }
    
    
    bool Controller::new_command_available()
    {
        return !scheduled_command_ptrs.empty();
    }
    
    
    void Controller::schedule_next_command()
    {
        current_command_ptr = scheduled_command_ptrs.front();
        scheduled_command_ptrs.pop();
    }
    
    
    void Controller::preempt_scheduled_commands()
    {
        scheduled_command_ptrs = std::queue<CommandPtr>();
    }
    
    
    void Controller::start_next_command()
    {
        // TODO : current_command_ptr.execute();
    }
    
    
    void Controller::check_moving_progress()
    {
        if (!al5d.is_moving())
        {
            schedule_event(EVENT_MOVING_FINISHED);
        }
    }
}
