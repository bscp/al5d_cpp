// 3TH PARTY INCLUDES
#include <gtest/gtest.h>

// PROJECT INCLUDES
#include <al5d_cpp/Joint.hpp>


TEST(Joint, move_joint_with_degrees)
{
    al5d::Joint joint(al5d::JointConfig(0, 1, 2, 3, 4));
    ASSERT_EQ(joint.angle_from_degrees(3), 1);
    ASSERT_EQ(joint.angle_from_degrees(4), 2);
}
