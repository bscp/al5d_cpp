// HEADER INCLUDE
#include <al5d_cpp/exceptions/InvalidDegrees.hpp>

#define MESSAGE "Invalid degrees given: "


namespace al5d
{
    InvalidDegrees::InvalidDegrees(
        const Degrees& degrees)
        : runtime_error(std::string(MESSAGE) + std::to_string(degrees))
    {
    }
}
