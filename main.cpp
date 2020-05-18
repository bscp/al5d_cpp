// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>

// TYPE DECLARATIONS
typedef al5d::Duration Duration;
typedef al5d::Degree Degree;


int main()
{
    const std::string al5d_file_path = "//workspaces//al5d_cpp//examples//al5d.json";
    auto al5d = al5d::AL5D::from_json_file(al5d_file_path);

    const std::string posing_file_path = "//workspaces//al5d_cpp//examples//al5d_posing.json";
    al5d.set_poses(al5d::AL5D::posing_config_from_json_file(posing_file_path));

    sleep(1); // in seconds

    // move to degree
    auto move_duration = Duration::from_ms(2000);
    al5d.move_to_degree(al5d::JOINT_BASE, Degree(90), move_duration);
    al5d.move_to_degrees({
        {al5d::JOINT_BASE, Degree(90)},
        {al5d::JOINT_SHOULDER, Degree(90)}},
        move_duration);

    // move to pose
    al5d.move_to_pose("ready", move_duration);

    sleep(1); // in seconds

    al5d.stop();
}
