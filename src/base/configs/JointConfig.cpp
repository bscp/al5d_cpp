// HEADER INCLUDE
#include <al5d_cpp/base/configs/JointConfig.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions/InvalidBoardChannel.hpp>
#include <al5d_cpp/exceptions/InvalidDegrees.hpp>


namespace al5d
{
    JointConfig::JointConfig(
        const JointName& name,
        const JointType& type,
        const BoardChannel& board_channel,
        const PulseWidthRange& pulse_width_range,
        const Degrees &min_degrees,
        const Degrees &max_degrees)
        : name(name)
        , type(type)
        , board_channel(board_channel)
        , pulse_width_range(pulse_width_range)
        , min_degrees(min_degrees)
        , max_degrees(max_degrees)
    {
        validate_board_channel_value(board_channel);
        validate_degrees_value(min_degrees);
        validate_degrees_value(max_degrees);
    }


    void JointConfig::validate_board_channel_value(
        BoardChannel board_channel)
        const
    {
        // BoardChannel is an unsigned type and thus always larger then zero
        if (board_channel > (BoardChannel)10)
        {
            throw InvalidBoardChannel(board_channel);
        }
    }


    void JointConfig::validate_degrees_value(
        Degrees degrees)
        const
    {
        if (degrees < (Degrees)-360)
        {
            throw InvalidDegrees(degrees);
        }
        if (degrees > (Degrees)360)
        {
            throw InvalidDegrees(degrees);
        }
    }
}
