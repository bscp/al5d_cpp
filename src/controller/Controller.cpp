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


    void Controller::set_start_state()
    {
        change_to_idling_state();
    }


    void Controller::schedule_pose_command(
        const PoseName& pose_name,
        const Duration& move_duration)
    {
        scheduled_command_ptrs.push(
            PoseCommand::as_pointer(this, pose_name, move_duration));
    }


    void Controller::schedule_angles_command(
        const JointTypeAngles& joint_type_angles,
        const Duration& move_duration)
    {
        scheduled_command_ptrs.push(
            AnglesCommand::as_pointer(this, joint_type_angles, move_duration));
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
        current_command_ptr->execute();
    }
    
    
    AL5DBase& Controller::get_al5d()
    {
        return al5d;
    }
    
    
    void Controller::check_moving_progress()
    {
        if (!al5d.is_moving())
        {
            schedule_event(EVENT_MOVING_FINISHED);
        }
    }
}
