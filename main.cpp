
// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>
#include <al5d_cpp/Duration.hpp>
#include <al5d_cpp/communicators/SerialCommunicator.hpp>
#include <al5d_cpp/Timer.hpp> // TODO : remove
#include <iostream> // TODO : remove
#include <string> // TODO : remove

int main()
{
    al5d::SerialPort serial_port("/dev/ttyUSB0");
    al5d::BaudRate serial_baud(9600);

    auto robot_ptr = al5d::AL5D::as_pointer();
    robot_ptr->connect(serial_port, serial_baud);

    const al5d::JointTypeAngles join_type_angles = {
        robot_ptr->angle_from_degrees(al5d::JOINT_BASE, 90),
//        robot_ptr->angle_from_degrees(al5d::JOINT_BASE, 0),
//        robot_ptr->angle_from_degrees(al5d::JOINT_BASE, 90),
//        robot_ptr->angle_from_pulse_width(al5d::JOINT_SHOULDER, 1500),
    };

    auto move_duration = al5d::Duration::from_milliseconds(2000);

//    robot_ptr->move_to(join_type_angles);
    robot_ptr->move_to(join_type_angles, move_duration);
    sleep(1);
    robot_ptr->do_emergency_stop();
}
