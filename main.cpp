
// SYSTEM INCLUDES
#include <string>
#include <iostream>
#include <functional>

// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>


int main()
{   
    const std::string file_path = "//workspaces//al5d_cpp//examples//json_config.json";
    auto al5d = al5d::AL5D::from_json_file(file_path);

    auto move_duration = al5d::Duration::from_milliseconds(2000);
    const al5d::JointTypeAngles joint_type_angles = {
        al5d.angle_from_degrees(al5d::JOINT_BASE, 90)
    };

    al5d.move_to(joint_type_angles, move_duration);
    
    sleep(1);

    al5d.do_emergency_stop();
}
