// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>


int main()
{
    // Initialize a al5d with a default configuration
    al5d_cpp::ConsoleAL5D al5d;


    // Initialize poses
    std::string path = "//workspaces//al5d_cpp//examples//3_controlled_al5d//al5d_poses.json";
    al5d.set_poses(al5d_cpp::poses_config_from_json_file(path));
    

    // Initialize al5d controller
    al5d_cpp::Controller al5d_controller(al5d);


    // Move joints to angles
    al5d_controller.schedule_angles_command(
        {
            {al5d_cpp::JOINT_BASE, al5d_cpp::Angle::from_degree(90)},
            {al5d_cpp::JOINT_SHOULDER, al5d_cpp::Angle::from_degree(90)}
        },
        al5d_cpp::Duration::from_ms(2000));


    // Move joints to pose config
    al5d_controller.schedule_pose_command(
        "ready", al5d_cpp::Duration::from_ms(2000));


    al5d_controller.set_start_state();
    while (true)
    {
        al5d_controller.run_once();
    }


    // Make emergency stop and dont allow for new commands
    al5d_controller.halt();
    sleep(1);
    al5d_controller.unhalt();


    return 0;    
}
