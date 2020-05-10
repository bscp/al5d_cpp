// HEADER INCLUDE
#include <al5d_cpp/exceptions/InvalidNumberOfJoints.hpp>

#define MESSAGE "Invalid number of joints in configuration. "


namespace al5d
{
    InvalidNumberOfJoints::InvalidNumberOfJoints(
        int number_of_given_joints)
        : runtime_error(std::string(MESSAGE) + "Expected '6' but got '" + std::to_string(number_of_given_joints) + "'") // TODO : shrink line size
    {
    }
}
