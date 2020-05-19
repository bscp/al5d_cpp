// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>
#include <al5d_cpp/controller/Controller.hpp>


int main()
{
    const std::string config_file = "//workspaces//al5d_cpp//examples//al5d.json";
    auto al5d = al5d::AL5D::from_json_file(config_file);
    al5d::Controller al5d_controller(al5d);


    // move multiple joints to angles over time
    al5d_controller.schedule_angles_command(
        {
            {al5d::JOINT_BASE, al5d::Angle::from_degree(90)},
            {al5d::JOINT_SHOULDER, al5d::Angle::from_degree(90)}
        },
        al5d::Duration::from_ms(2000));


    // move to a named pose
    al5d_controller.schedule_pose_command(
        "ready", al5d::Duration::from_ms(2000));


    // move single joint to angle over time
    al5d_controller.schedule_angle_command(
        {al5d::JOINT_BASE, al5d::Angle::from_degree(90)},
        al5d::Duration::from_ms(2000));


    while (true)
    {
        al5d_controller.run_once();
    }


    return 0;    
}
