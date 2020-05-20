// // 3TH PARTY INCLUDES
// #include <gtest/gtest.h>

// // PROJECT INCLUDES
// #include <al5d_cpp/AL5D.hpp>


// TEST(AL5D, angle_from_degrees_positive)
// {
//     al5d_cpp::SerialPort serial_port("/dev/ttyUSB0");
//     al5d_cpp::BaudRate serial_baud(9600);
//     al5d_cpp::JointBaseConfig joint_config_1({al5d_cpp::JOINT_BASE, 1, 3, 3, 5});
//     al5d_cpp::JointBaseConfig joint_config_2({al5d_cpp::JOINT_SHOULDER, 5, 7, 7, 9});
//     al5d_cpp::AL5DConfig al5d_config(serial_port, serial_baud, {joint_config_1, joint_config_2});
//     auto robot_ptr = al5d_cpp::AL5D::as_pointer(al5d_config);

//     // Testing JOINT_BASE
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, 3).joint_angle, 1);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, 4).joint_angle, 2);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, 5).joint_angle, 3);

//     // Testing JOINT_SHOULDER
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_SHOULDER, 7).joint_angle, 5);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_SHOULDER, 8).joint_angle, 6);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_SHOULDER, 9).joint_angle, 7);
// }


// TEST(AL5D, angle_from_degrees_negative)
// {
//     // Only degree values can be negative, pwm values can't
//     al5d_cpp::SerialPort serial_port("/dev/ttyUSB0");
//     al5d_cpp::BaudRate serial_baud(9600);
//     al5d_cpp::JointBaseConfig joint_config_1({al5d_cpp::JOINT_BASE, 1, 3, -3, -5});
//     al5d_cpp::JointBaseConfig joint_config_2({al5d_cpp::JOINT_SHOULDER, 5, 7, -7, -9});
//     al5d_cpp::AL5DConfig al5d_config(serial_port, serial_baud, {joint_config_1, joint_config_2});
//     auto robot_ptr = al5d_cpp::AL5D::as_pointer(al5d_config);

//     // Testing JOINT_BASE
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, -3).joint_angle, 1);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, -4).joint_angle, 2);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, -5).joint_angle, 3);

//     // Testing JOINT_SHOULDER
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_SHOULDER, -7).joint_angle, 5);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_SHOULDER, -8).joint_angle, 6);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_SHOULDER, -9).joint_angle, 7);
// }


// TEST(AL5D, angle_from_degrees_mixed)
// {
//     // only degree values can be negative, pwm values can't
//     al5d_cpp::SerialPort serial_port("/dev/ttyUSB0");
//     al5d_cpp::BaudRate serial_baud(9600);
//     al5d_cpp::JointBaseConfig joint_config_1({al5d_cpp::JOINT_BASE, 2, 4, -1, 1});
//     al5d_cpp::JointBaseConfig joint_config_2({al5d_cpp::JOINT_SHOULDER, 4, 6, -1, 1});
//     al5d_cpp::AL5DConfig al5d_config(serial_port, serial_baud, {joint_config_1, joint_config_2});
//     auto robot_ptr = al5d_cpp::AL5D::as_pointer(al5d_config);

//     // Testing JOINT_BASE
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, -1).joint_angle, 2);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, 0).joint_angle, 3);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, 1).joint_angle, 4);

//     // Testing JOINT_SHOULDER
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_SHOULDER, -1).joint_angle, 4);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_SHOULDER, 0).joint_angle, 5);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_SHOULDER, 1).joint_angle, 6);
// }


// TEST(AL5D, angle_from_degrees_reversed)
// {
//     // only degree values can be reversed, pwm values can't
//     al5d_cpp::SerialPort serial_port("/dev/ttyUSB0");
//     al5d_cpp::BaudRate serial_baud(9600);
//     al5d_cpp::JointBaseConfig joint_config_1({al5d_cpp::JOINT_BASE, 2, 4, 1, -1});
//     al5d_cpp::JointBaseConfig joint_config_2({al5d_cpp::JOINT_SHOULDER, 4, 6, 2, -2});
//     al5d_cpp::AL5DConfig al5d_config(serial_port, serial_baud, {joint_config_1, joint_config_2});
//     auto robot_ptr = al5d_cpp::AL5D::as_pointer(al5d_config);

//     // Testing JOINT_BASE
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, 1).joint_angle, 2);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, 0).joint_angle, 3);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_BASE, -1).joint_angle, 4);

//     // Testing JOINT_SHOULDER
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_SHOULDER, 2).joint_angle, 4);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_SHOULDER, 0).joint_angle, 5);
//     ASSERT_EQ(robot_ptr->angle_from_degrees(al5d_cpp::JOINT_SHOULDER, -2).joint_angle, 6);
// }
