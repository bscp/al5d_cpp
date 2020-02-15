
#define BOOST_TEST_DYN_LINK

// 3TH PARTY INCLUDES
#include <boost/test/unit_test.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/AL5D6D.hpp>
#include <al5d_cpp/Communicator.hpp>

// TESTABLE INCLUDES
#include "testables/TestableAL5D6D.hpp"
#include "testables/TestableCommunicator.hpp"


BOOST_AUTO_TEST_SUITE(AL5D6D)


BOOST_AUTO_TEST_CASE(STOP)
{
    auto communicator_ptr = std::make_shared<al5d::TestableCommunicator>();
    al5d::TestableAL5D6D al5d6d(communicator_ptr);
    
    al5d6d.stop();
    BOOST_CHECK_EQUAL(communicator_ptr->get_transmitted_message(), "STOP\r");
}


BOOST_AUTO_TEST_CASE(JOINT_PULSE_WIDTH_RANGES)
{
    al5d::TestableAL5D6D al5d6d;

    BOOST_CHECK_THROW(al5d6d.move_to_pulse_widths({{al5d::JOINT_BASE, 499}}), std::invalid_argument);
    BOOST_CHECK_NO_THROW(al5d6d.move_to_pulse_widths({{al5d::JOINT_BASE, 500}}));
    BOOST_CHECK_NO_THROW(al5d6d.move_to_pulse_widths({{al5d::JOINT_BASE, 2500}}));
    BOOST_CHECK_THROW(al5d6d.move_to_pulse_widths({{al5d::JOINT_BASE, 2501}}), std::invalid_argument);
}


BOOST_AUTO_TEST_CASE(JOINT_DEGREE_RANGES)
{
    al5d::TestableAL5D6D al5d6d;
    
    BOOST_CHECK_THROW(al5d6d.move_to_degrees({{al5d::JOINT_BASE, -91}}), std::invalid_argument);
    BOOST_CHECK_NO_THROW(al5d6d.move_to_degrees({{al5d::JOINT_BASE, -90}}));
    BOOST_CHECK_NO_THROW(al5d6d.move_to_degrees({{al5d::JOINT_BASE, 90}}));
    BOOST_CHECK_THROW(al5d6d.move_to_degrees({{al5d::JOINT_BASE, 91}}), std::invalid_argument);
}


BOOST_AUTO_TEST_CASE(MOVE_TO_PULSE_WIDTH)
{
    auto communicator_ptr = std::make_shared<al5d::TestableCommunicator>();
    al5d::TestableAL5D6D al5d6d(communicator_ptr);
    
    std::string transmitted_message;

    // SINGLE // VALID
    al5d6d.move_to_pulse_widths({{al5d::JOINT_BASE, 1500}});
    BOOST_CHECK_EQUAL(communicator_ptr->get_transmitted_message(), "#0P1500\r");

    // MULTIPLE // VALID
    al5d6d.move_to_pulse_widths({{al5d::JOINT_BASE, 1500}, {al5d::JOINT_SHOULDER, 1500}});
    BOOST_CHECK_EQUAL(communicator_ptr->get_transmitted_message(), "#0P1500#1P1500\r");
}


BOOST_AUTO_TEST_SUITE_END()
