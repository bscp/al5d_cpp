// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>


int main()
{
    const std::string al5d_file_path = "//workspaces//al5d_cpp//examples//al5d.json";
    auto al5d = al5d::AL5D::from_json_file(al5d_file_path);

    const std::string poses_file_path = "//workspaces//al5d_cpp//examples//al5d_poses.json";
    al5d.add_poses(al5d::AL5D::pose_configs_from_json_file(poses_file_path));

    // move to degree
    auto move_duration = al5d::Duration::from_milliseconds(2000);
    al5d.move_to_degree(al5d::JointType::JOINT_BASE, al5d::Degree(90), move_duration);
    al5d.move_to_degree(al5d::JOINT_BASE, al5d::Degree(90), move_duration);
    al5d.move_to_degrees({
        {al5d::JOINT_BASE, al5d::Degree(90)},
        {al5d::JOINT_SHOULDER, al5d::Degree(90)}},
        move_duration);

    // move to pose
    al5d.move_to_pose("test1");
    al5d.move_to_pose("test1", move_duration);

    sleep(2); // seconds
    al5d.stop();
}
