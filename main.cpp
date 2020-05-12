// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>


int main()
{
    const std::string al5d_file_path = "//workspaces//al5d_cpp//examples//al5d.json";
    auto al5d = al5d::AL5D::from_json_file(al5d_file_path);
    al5d.print_poses();

    const std::string poses_file_path = "//workspaces//al5d_cpp//examples//al5d_poses.json";
    al5d.add_poses(al5d::AL5D::pose_configs_from_json_file(poses_file_path));
    al5d.print_poses();

    // move to degrees
    auto move_duration = al5d::Duration::from_milliseconds(2000);
    al5d.move_to(al5d::JOINT_BASE, al5d::Degrees(90));
    al5d.move_to(al5d::JOINT_BASE, al5d::Degrees(90), move_duration);
    al5d.move_to({
        {al5d::JOINT_BASE, al5d::Degrees(90)},
        {al5d::JOINT_SHOULDER, al5d::Degrees(90)}});

    // move to pose
    al5d.move_to_pose("test1");
    al5d.move_to_pose("test1", move_duration);


    std::this_thread::sleep_for(std::chrono::seconds(2));
    al5d.stop();
}
