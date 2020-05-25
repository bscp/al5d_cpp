// HEADER INCLUDE
#include <al5d_cpp/base/configs/JointBaseConfig.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions.hpp>
#include <al5d_cpp/exceptions.hpp>


namespace al5d_cpp
{
    JointBaseConfig::JointBaseConfig(
        const JointName& name,
        const JointType& type,
        const BoardChannel& board_channel,
        const PulseWidthRange& pulse_width_range,
        const DegreeRange &degree_range)
        : name(name)
        , type(type)
        , board_channel(board_channel)
        , pulse_width_range(pulse_width_range)
        , degree_range(degree_range)
    {
        validate_board_channel();
    }


    void JointBaseConfig::validate_board_channel()
        const
    {
        // BoardChannel is an unsigned type and thus always larger then zero
        if (board_channel > BoardChannel(10))
        {
            throw InvalidBoardChannel(board_channel);
        }
    }
}
