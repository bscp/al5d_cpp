// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>


int main()
{
    // Initialize a al5d with a default configuration
    al5d_cpp::ConsoleAL5D al5d;

    // Initialize poses from json configuration
    std::string path("//workspaces//al5d_cpp//examples//2_move_to_pose//al5d_poses.json");
    al5d.set_poses(al5d_cpp::poses_config_from_json_file(path));

    // Move to pose named "ready"
    al5d.move_to_pose("ready");

    // Move to pose named "park" over 2000 milliseconds
    auto move_duration = al5d_cpp::Duration::from_milliseconds(2000);
    al5d.move_to_pose("park", move_duration);

    return 0;    
}
