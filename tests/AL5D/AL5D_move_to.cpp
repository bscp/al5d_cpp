// // 3TH PARTY INCLUDES
// #include <gtest/gtest.h>

// // PROJECT INCLUDES
// #include <al5d_cpp/AL5D.hpp>

// // TEST INCLUDES
// #include "../testables/TestableCommunicator.hpp" // TODO : implement as Mixin


// TEST(AL5D, move_to_single)
// {
//     al5d_cpp::JointBaseConfig joint_config_1({al5d_cpp::JOINT_BASE, 1, 3, 3, 5});
//     al5d_cpp::SerialPort serial_port("/dev/ttyUSB0");
//     al5d_cpp::BaudRate serial_baud(9600);
//     auto robot_ptr = al5d_cpp::AL5D::as_pointer(al5d_cpp::AL5DConfig(serial_port, serial_baud, {joint_config_1}));
//     al5d_cpp::TestableCommunicator communicator;
//     al5d_cpp::CommunicatorPtr communicator_ptr = std::make_shared<Communicator>(communicator);
//     robot_ptr->set_communicator(communicator_ptr);

//     robot_ptr->move_to(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, 3));
//     ASSERT_EQ(communicator.transmitted, "#0P1\n");
    
//     robot_ptr->move_to(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, 4));
//     ASSERT_EQ(communicator.transmitted, "#0P2\n");

//     robot_ptr->move_to(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, 5));
//     ASSERT_EQ(communicator.transmitted, "#0P3\n");
// }
