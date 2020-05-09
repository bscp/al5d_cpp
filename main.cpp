// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>


int main()
{   
    const std::string file_path = "//workspaces//al5d_cpp//examples//json_config.json";
    auto al5d = al5d::AL5D::from_json_file(file_path);

    auto move_duration = al5d::Duration::from_milliseconds(2000);
    al5d.move_to({{al5d::JOINT_BASE, 90}}, move_duration);

    move_duration = al5d::Duration::from_milliseconds(2000);
    al5d.move_to({{al5d::JOINT_SHOULDER, 90}}, move_duration);
    
    sleep(1);

    al5d.stop();
}
