// 3TH PARTY INCLUDES
#include <gtest/gtest.h>

// SYSTEM INCLUDES
#include <memory>

// PROJECT INCLUDES
#include <al5d_cpp/base/JointBase.hpp>

typedef std::shared_ptr<class TestableCommunicator> TestableCommunicatorPtr;

class TestableCommunicator : public al5d::Communicator
{
public:
    static TestableCommunicatorPtr as_ptr()
    {
        return std::make_shared<TestableCommunicator>();
    }

    virtual void transmit(
        const std::string& message)
    {
        transmitted += message;
    }

    std::string get_transmitted()
    {
        const auto temp = transmitted;
        transmitted = "";
        return temp;
    }

private:

    std::string transmitted;
};


class TestableJointConfig : public al5d::JointConfig
{
public:
    TestableJointConfig(
        const al5d::PulseWidthRange& p_range,
        const al5d::DegreeRange& d_range)
        : JointConfig("base", al5d::JOINT_BASE, 0, p_range, d_range)
    {
    }
};


class TestableJointBase : public al5d::JointBase
{
public:
    TestableJointBase(
        const al5d::JointConfig& config,
        const al5d::CommunicatorPtr& communicator_ptr)
        : JointBase(config)
    {
        set_communicator_ptr(communicator_ptr);
    }
};


TEST(Joint, move_joint)
{
    auto com = TestableCommunicator::as_ptr();
    TestableJointConfig config({100, 300}, {1, 3});
    TestableJointBase joint(config, com);

    joint.move_to_angle(al5d::Angle::from_degree(1));
    ASSERT_EQ(com->get_transmitted(), "#0P100");

    joint.move_to_angle(al5d::Angle::from_degree(2));
    ASSERT_EQ(com->get_transmitted(), "#0P200");

    joint.move_to_angle(al5d::Angle::from_degree(3));
    ASSERT_EQ(com->get_transmitted(), "#0P300");
}



TEST(Joint, move_reversed_joint)
{
    auto com = TestableCommunicator::as_ptr();
    TestableJointConfig config({100, 300}, {3, 1});
    TestableJointBase joint(config, com);

    joint.move_to_angle(al5d::Angle::from_degree(1));
    ASSERT_EQ(com->get_transmitted(), "#0P300");

    joint.move_to_angle(al5d::Angle::from_degree(2));
    ASSERT_EQ(com->get_transmitted(), "#0P200");

    joint.move_to_angle(al5d::Angle::from_degree(3));
    ASSERT_EQ(com->get_transmitted(), "#0P100");
}
