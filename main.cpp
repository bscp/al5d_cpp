// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>


int main()
{
    const std::string file_path = "//workspaces//al5d_cpp//examples//json_config.json";
    auto al5d = al5d::AL5D::from_json_file(file_path);

    auto move_duration = al5d::Duration::from_milliseconds(2000);
    al5d.move_to(al5d::JOINT_BASE, al5d::Degrees(90), move_duration);
    al5d.move_to_pose("test");


    std::this_thread::sleep_for(std::chrono::seconds(2));
    al5d.stop();
}
