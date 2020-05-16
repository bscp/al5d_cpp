// HEADER INCLUDE
#include <al5d_cpp/exceptions/InvalidPoseName.hpp>

#define MESSAGE "Invalid pose name given: "


namespace al5d
{
    InvalidPoseName::InvalidPoseName(
        const std::string& pose_name)
        : runtime_error(std::string(MESSAGE) + pose_name)
    {
    }
}
