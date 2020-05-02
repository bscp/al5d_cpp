
// SYSTEM INCLUDES
#include <string>
#include <iostream>
#include <functional>

// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>


int main()
{
    typedef al5d::LambdaAL5D Robot;

    Robot::Config config;
    // config.serial_port =al5d::SerialPort("/dev/ttyUSB0");
    // config.serial_baud = al5d::BaudRate(9600);

    config.joint_configs = {
        al5d::JointConfig({0, 500, 2500, -90,  90}), // BASE_JOINT
        al5d::JointConfig({1, 500, 2500, -30,  90}), // SHOULDER_JOINT
        al5d::JointConfig({2, 500, 2500,   0, 135}), // ELBOW_JOINT
        al5d::JointConfig({3, 500, 2500, -90,  90}), // WRIST_JOINT
        al5d::JointConfig({4, 500, 2500, -90,  90}), // WRIST_ROTATE_JOINT
        al5d::JointConfig({5, 500, 2500,   0,   1}), // GRIPPER_JOINT
    };

    config.on_transmit_fn = [](const std::string& message)
    {
        std::cout << message << "\n";
    };

    Robot robot(config);

    const al5d::JointTypeAngles join_type_angles = {
        robot.angle_from_degrees(al5d::JOINT_BASE, 90),
//        robot.angle_from_degrees(al5d::JOINT_BASE, 0),
//        robot.angle_from_degrees(al5d::JOINT_BASE, 90),
//        robot.angle_from_pulse_width(al5d::JOINT_SHOULDER, 1500),
    };

    robot.move_to(join_type_angles, al5d::Duration::from_milliseconds(2000));
    sleep(1);
    robot.do_emergency_stop();
}
