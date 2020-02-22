
// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>
#include <al5d_cpp/Duration.hpp>

int main()
{
    std::string serial_port = "/dev/ttyUSB0";
    long serial_baudrate = 9600;
    
    auto robot = al5d::AL5D::from_default_config();
    robot.connect(serial_port, serial_baudrate);
    
    const al5d::JointTypeAngles join_type_angles = {
        robot.joint_angle_from_degrees(al5d::JOINT_BASE, -90),
        robot.joint_angle_from_degrees(al5d::JOINT_BASE, 0),
        robot.joint_angle_from_degrees(al5d::JOINT_BASE, 90),
        robot.joint_angle_from_pulse_width(al5d::JOINT_SHOULDER, 1500),
    };
    
    auto move_duration = al5d::Duration::from_milliseconds(2300);
    
    robot.start_moving_joints(join_type_angles);
    robot.start_moving_joints(join_type_angles, move_duration);
    
    robot.do_emergency_stop();
}
