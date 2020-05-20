// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>

// TYPE DECLARATIONS
typedef al5d_cpp::Duration Duration;
typedef al5d_cpp::Degree Degree;
typedef al5d_cpp::Angle Angle;


int main()
{
    const std::string al5d_file_path = "//workspaces//al5d_cpp//examples//al5d.json";
    auto al5d = al5d_cpp::AL5D::from_json_file(al5d_file_path);

    const std::string posing_file_path = "//workspaces//al5d_cpp//examples//al5d_posing.json";
    al5d.set_poses(al5d_cpp::AL5D::posing_config_from_json_file(posing_file_path));

    sleep(1); // in seconds

    // move multiple joints to degree
    al5d.move_to_angles({
        {al5d_cpp::JOINT_BASE, Angle::from_degree(90)},
        {al5d_cpp::JOINT_SHOULDER, Angle::from_degree(90)}},
        Duration::from_ms(2000));
    sleep(2);

    // move multiple joints to a named pose
    al5d.move_to_pose("ready", Duration::from_ms(2000));
    sleep(2);

    // move single joint to degree
    auto& base_joint = al5d.get_joint(al5d_cpp::JOINT_BASE); // TODO : make const
    base_joint.move_to_angle(Angle::from_degree(90), Duration::from_ms(2000));
    sleep(2);

    // stop single joint
    base_joint.stop();

    // stop all joints
    al5d.stop();
}
