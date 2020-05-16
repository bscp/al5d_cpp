#ifndef SRC_INVALIDPOSENAME_HPP
#define SRC_INVALIDPOSENAME_HPP

// SYSTEM INCLUDES
#include <stdexcept>
#include <string>


namespace al5d
{
    class InvalidPoseName : public std::runtime_error
    {
    public:
        explicit InvalidPoseName(
            const std::string& pose_name);
    };
}


#endif // SRC_INVALIDPOSENAME_HPP
