
// #define BOOST_TEST_DYN_LINK

// // 3TH PARTY INCLUDES
// #include <boost/test/unit_test.hpp>

// // PROJECT INCLUDES
// #include <al5d_cpp/Joint.hpp>

// BOOST_AUTO_TEST_SUITE(JOINT)


// BOOST_AUTO_TEST_CASE(move_command_from_degrees)
// {
//     { // NORMAL JOINT
//         al5d::JointBaseConfig config(0, 1, 2, 3, 4);
//         al5d::Joint joint(config);
        
//         BOOST_CHECK_EQUAL(joint.move_command_from_degrees(3), "#0P1");
//         BOOST_CHECK_EQUAL(joint.move_command_from_degrees(4), "#0P2");
//     }
// //    { // REVERSED DEGREES JOINT
// //        al5d::JointBaseConfig config(0, 1, 2, 4, 3);
// //        al5d::Joint joint(config);
// //
// //        BOOST_CHECK_EQUAL(joint.to_pulse_width(4), 1); // TODO
// //        BOOST_CHECK_EQUAL(joint.to_pulse_width(3), 2);
// //    }
// //    { // REVERSED PULSE WIDTH JOINT
// //        al5d::JointBaseConfig config(0, 2, 1, 3, 4);
// //        al5d::Joint joint(config);
// //
// //        BOOST_CHECK_EQUAL(joint.move_command_from_degrees(3), "#0P2\r");
// //        BOOST_CHECK_EQUAL(joint.move_command_from_degrees(4), "#0P1\r");
// //    }
// }


// BOOST_AUTO_TEST_CASE(CAN_REACH_DEGREES)
// {
//     al5d::JointBaseConfig config(0, 1, 2, 3, 4);
//     al5d::Joint joint(config);
    
//     BOOST_CHECK_THROW(joint.move_command_from_degrees(2), std::invalid_argument);
//     BOOST_CHECK_NO_THROW(joint.move_command_from_degrees(3));
//     BOOST_CHECK_NO_THROW(joint.move_command_from_degrees(4));
//     BOOST_CHECK_THROW(joint.move_command_from_degrees(5), std::invalid_argument);
// }


// BOOST_AUTO_TEST_CASE(CAN_REACH_PULSE_WIDTH)
// {
//     al5d::JointBaseConfig config(0, 1, 2, 3, 4);
//     al5d::Joint joint(config);
    
//     BOOST_CHECK_THROW(joint.move_command_from_pulse_width(0), std::invalid_argument);
//     BOOST_CHECK_NO_THROW(joint.move_command_from_pulse_width(1));
//     BOOST_CHECK_NO_THROW(joint.move_command_from_pulse_width(2));
//     BOOST_CHECK_THROW(joint.move_command_from_pulse_width(3), std::invalid_argument);
// }


// BOOST_AUTO_TEST_SUITE_END()
