// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>


int main()
{
    // Initialize al5d
    std::string path("//workspaces//al5d_cpp//examples//al5d.json");
    auto al5d = al5d::AL5D(al5d::al5d_config_from_json_file(path));

    // Initialize poses
    path = "//workspaces//al5d_cpp//examples//al5d_poses.json";
    al5d.set_poses(al5d::poses_config_from_json_file(path));
    
    // Initialize al5d controller
    al5d::Controller al5d_controller(al5d);

    // Move joints to angles
    al5d_controller.schedule_angles_command(
        {
            {al5d::JOINT_BASE, al5d::Angle::from_degree(90)},
            {al5d::JOINT_SHOULDER, al5d::Angle::from_degree(90)}
        },
        al5d::Duration::from_ms(2000));

    // Move joints to pose config
    al5d_controller.schedule_pose_command(
        "ready", al5d::Duration::from_ms(2000));

    al5d_controller.set_start_state();
    while (true)
    {
        al5d_controller.run_once();
    }

    return 0;    
}
