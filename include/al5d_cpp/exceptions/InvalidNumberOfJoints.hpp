#ifndef SRC_INVALIDNUMBEROFJOINTS_HPP
#define SRC_INVALIDNUMBEROFJOINTS_HPP

// SYSTEM INCLUDES
#include <stdexcept>


namespace al5d
{
    class InvalidNumberOfJoints : public std::runtime_error
    {
    public:
        explicit InvalidNumberOfJoints(
            int number_of_given_joints);
    };
}


#endif // SRC_INVALIDNUMBEROFJOINTS_HPP