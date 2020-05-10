// HEADER INCLUDE
#include <al5d_cpp/exceptions/InvalidBoardChannel.hpp>

#define MESSAGE "Invalid board channel given: "


namespace al5d
{
    InvalidBoardChannel::InvalidBoardChannel(
        const BoardChannel& board_channel)
        : runtime_error(std::string(MESSAGE) + std::to_string(board_channel))
    {
    }
}
