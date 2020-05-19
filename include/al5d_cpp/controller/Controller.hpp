#ifndef AL5D_CPP_CONTROLLER_HPP
#define AL5D_CPP_CONTROLLER_HPP

// SYSTEM INCLUDES
#include <queue>

// PROJECT INCLUDES
#include <al5d_cpp/controller/Command.hpp>
#include <al5d_cpp/controller/Context.hpp>
#include <al5d_cpp/base/AL5DBase.hpp>


namespace al5d
{
    class Controller : public Context
    {
    public:

        explicit Controller(
            const AL5DBase& al5d);

        virtual ~Controller();

        void set_start_state()
            override;

        void change_to_idling_state();
        void change_to_moving_state();
        void change_to_halting_state();

        // void schedule_angle_command(
        //     const JointTypeAngle& joint_type_angle,
        //     const Duration& move_duration);
        // void schedule_angles_command(
        //     const JointTypeAngles& joint_type_angles,
        //     const Duration& move_duration);
        void schedule_pose_command(
            const PoseName& pose_name,
            const Duration& move_duration);

        void execute_pose_command();
        void schedule_next_command_if_available();
        void preempt_scheduled_commands();
        void start_next_command();
        void check_moving_progress();

    protected:

        bool new_command_available();

        void schedule_next_command(); // TODO : rename to start_next_command

        std::queue<CommandPtr> scheduled_command_ptrs;
        CommandPtr current_command_ptr;
    
    private:

        AL5DBase al5d;
    };
}


#endif // AL5D_CPP_CONTROLLER_HPP
