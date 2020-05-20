// // // 3TH PARTY INCLUDES
// #include <gtest/gtest.h>

// // PROJECT INCLUDES
// #include <al5d_cpp/base/AL5DBase.hpp>
// #include <al5d_cpp/traits/json_trait/JSONTrait.hpp>

// // TEST INCLUDES
// #include "TestableTrait.hpp"


// namespace al5d
// {
//     typedef JSONTrait<TestableTrait<AL5DBase>>
//         TestableConfigurableAL5D;
// }


// al5d::TestableConfigurableAL5D load_al5d(
//     const std::string& file_path)
// {
//     return al5d::TestableConfigurableAL5D::from_json_file(file_path);    
// }


// TEST(JSONTrait, load_multiple_joints)
// {
//     auto al5d = load_al5d("/workspaces/al5d_cpp/tests/traits/configurable_trait/multiple_joints.json");
//     ASSERT_EQ(al5d.get_joints().size(), 6);
// }


// TEST(JSONTrait, load_single_joint)
// {
//     auto al5d = load_al5d("/workspaces/al5d_cpp/tests/traits/configurable_trait/single_joint.json");
//     auto joint = al5d.get_joints()[0];
//     // ASSERT_EQ(joint., 6);
// }
