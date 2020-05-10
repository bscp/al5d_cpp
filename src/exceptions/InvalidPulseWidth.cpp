// HEADER INCLUDE
#include <al5d_cpp/exceptions/InvalidPulseWidth.hpp>

#define MESSAGE "Invalid pulse width given: "


namespace al5d
{
    InvalidPulseWidth::InvalidPulseWidth(
        const BoardChannel& board_channel)
        : runtime_error(std::string(MESSAGE) + std::to_string(board_channel))
    {
    }
}
