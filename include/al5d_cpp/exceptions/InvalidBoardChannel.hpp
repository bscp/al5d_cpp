#ifndef SRC_INVALIDBOARDCHANNEL_HPP
#define SRC_INVALIDBOARDCHANNEL_HPP

// SYSTEM INCLUDES
#include <stdexcept>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    class InvalidBoardChannel : public std::runtime_error
    {
    public:
        explicit InvalidBoardChannel(
            const BoardChannel& board_channel);
    };
}


#endif // SRC_INVALIDBOARDCHANNEL_HPP