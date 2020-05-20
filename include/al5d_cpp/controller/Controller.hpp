#ifndef AL5D_CPP_CONTROLLER_HPP
#define AL5D_CPP_CONTROLLER_HPP

// SYSTEM INCLUDES
#include <queue>

// PROJECT INCLUDES
#include <al5d_cpp/controller/Command.hpp>
#include <al5d_cpp/controller/Context.hpp>
#include <al5d_cpp/base/AL5DBase.hpp>
#include <al5d_cpp/settings.hpp>


namespace al5d
{
    class Controller : public Context
    {
    public:

        explicit Controller(
            const AL5DBase& al5d);

        void set_start_state()
            override;

        void change_to_connecting_state();
        void change_to_idling_state();
        void change_to_moving_state();
        void change_to_halting_state();

        void schedule_angles_command(
            const JointTypeAngles& joint_type_angles,
            const Duration& move_duration
                =Duration::from_ms(MOVE_DURATION));

        void schedule_pose_command(
            const PoseName& pose_name,
            const Duration& move_duration
                =Duration::from_ms(MOVE_DURATION));

        void schedule_next_command_if_available();
        void preempt_scheduled_commands();
        void start_next_command();
        void check_moving_progress();
        void check_connecting_progress();

        AL5DBase& get_al5d();

    protected:

        bool new_command_available()
            const;

        void schedule_next_command();

        std::queue<CommandPtr> scheduled_command_ptrs;
        CommandPtr current_command_ptr;
    
    private:

        AL5DBase al5d;
    };
}


#endif // AL5D_CPP_CONTROLLER_HPP
