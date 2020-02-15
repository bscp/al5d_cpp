
// PROJECT INCLUDES
#include <al5d_cpp/AL5D6D.hpp>
#include <al5d_cpp/AL5D6DConfig.hpp>

int main()
{
    al5d::AL5D6DConfig config;
    config.base_joint_config = al5d::JointConfig(0, 500, 2500, -90, 90);
    config.shoulder_joint_config = al5d::JointConfig(1, 500, 2500, -90, 90);
    config.elbow_joint_config = al5d::JointConfig(2, 500, 2500, -90, 90);
    config.wrist_joint_config = al5d::JointConfig(3, 500, 2500, -90, 90);
    config.gripper_joint_config = al5d::JointConfig(4, 500, 2500, -90, 90);
    config.wrist_rotate_joint_config = al5d::JointConfig(5, 500, 2500, -90, 90);
    
    al5d::AL5D6D al5d6d("/dev/ttyUSB0", config);

    al5d6d.move_to_degrees({
        {al5d::JOINT_BASE, 90},
        {al5d::JOINT_SHOULDER, 90},
    });

    al5d6d.stop();
}
