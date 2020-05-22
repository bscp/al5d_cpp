// HEADER INCLUDE
#include <al5d_cpp/controller/Controller.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/controller/events.hpp>
#include <al5d_cpp/controller/states.hpp>
#include <al5d_cpp/controller/commands.hpp>


namespace al5d_cpp
{
    Controller::Controller(
        const AL5DBase& al5d)
        : Context()
        , al5d(al5d)
    {
    }


    void Controller::set_start_state()
    {
        change_to_connecting_state();
    }


    void Controller::schedule_pose_command(
        const PoseName& pose_name,
        const Duration& move_duration)
    {
        schedule_command(
            PoseCommand::as_pointer(this, pose_name, move_duration));
    }


    void Controller::schedule_angles_command(
        const JointTypeAngles& joint_type_angles,
        const Duration& move_duration)
    {
        schedule_command(
            AnglesCommand::as_pointer(this, joint_type_angles, move_duration));
    }


    void Controller::schedule_command(
        const CommandPtr& command_ptr)
    {
        scheduled_command_ptrs.push(command_ptr);
    }


    void Controller::change_to_connecting_state()
    {
        change_state(ConnectingState::as_pointer(this));
    }


    void Controller::change_to_calibrating_state()
    {
        change_state(CalibratingState::as_pointer(this));
    }


    void Controller::change_to_initializing_state()
    {
        change_state(InitializingState::as_pointer(this));
    }


    void Controller::change_to_idling_state()
    {
        change_state(IdlingState::as_pointer(this));
    }


    void Controller::change_to_moving_state()
    {
        change_state(MovingState::as_pointer(this));
    }


    void Controller::change_to_finalizing_state()
    {
        change_state(FinalizingState::as_pointer(this));
    }


    void Controller::change_to_halting_state()
    {
        change_state(HaltingState::as_pointer(this));
    }


    void Controller::halt()
    {
        al5d.stop();
        change_to_halting_state();
        preempt_scheduled_commands();
    }


    void Controller::unhalt()
    {
        schedule_event(UNHALT_COMMAND_RECEIVED);
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
        const
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
    
    
    void Controller::start_calibrating()
    {
        al5d.move_to_calibrating_pose();
    }
    
    
    void Controller::start_initializing()
    {
        al5d.move_to_start_pose();
    }
    
    
    void Controller::start_finalizing()
    {
        al5d.move_to_finish_pose();
    }
    
    
    void Controller::start_next_command()
    {
        current_command_ptr->execute();
    }
    
    
    AL5DBase& Controller::get_al5d()
    {
        return al5d;
    }
    
    
    void Controller::check_initializing_progress()
    {
        if (!al5d.is_moving())
        {
            schedule_event(EVENT_INITIALIZING_FINISHED);
        }
    }
    
    
    void Controller::check_calibrating_progress()
    {
        // TODO : make DRY together with initializing, moving, finalizing
        if (!al5d.is_moving())
        {
            schedule_event(EVENT_CALIBRATING_FINISHED);
        }
    }
    
    
    void Controller::check_finalizing_progress()
    {
        if (!al5d.is_moving())
        {
            schedule_event(EVENT_FINALIZING_FINISHED);
        }
    }
    
    
    void Controller::check_moving_progress()
    {
        if (!al5d.is_moving())
        {
            schedule_event(EVENT_MOVING_FINISHED);
        }
    }
    
    
    void Controller::check_connecting_progress()
    {
        if (al5d.is_connected())
        {
            schedule_event(EVENT_CONNECTING_FINISHED);
        }
    }
}
