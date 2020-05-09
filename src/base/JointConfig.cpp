// HEADER INCLUDE
#include <al5d_cpp/base/JointConfig.hpp>


namespace al5d
{
    JointConfig::JointConfig(const BoardChannel &boardChannel, const PulseWidth &minPulseWidth,
                             const PulseWidth &maxPulseWidth, const Degrees &min_degrees,
                             const Degrees &max_degrees)
        : board_channel(boardChannel)
        , min_pulse_width(minPulseWidth)
        , max_pulse_width(maxPulseWidth)
        , min_degrees(min_degrees)
        , max_degrees(max_degrees)
    {
        validate_board_channel_value(board_channel);
        validate_pulse_width_value(min_pulse_width);
        validate_pulse_width_value(max_pulse_width);
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
            throw "Board channel can not be larger than 10"; // TODO : throw class and more info
        }
    }


    void JointConfig::validate_pulse_width_value(
        PulseWidth pulse_width)
        const
    {
        // PulseWidth is an unsigned type and thus always larger then zero
        if (pulse_width > (PulseWidth)10000)
        {
            throw "Pulse width can not be smaller than 10000"; // TODO : throw class and more info
        }
    }


    void JointConfig::validate_degrees_value(
        Degrees degrees)
        const
    {
        if (degrees < (Degrees)-360)
        {
            throw "Degrees can not be smaller than -360"; // TODO : throw class and more info
        }
        if (degrees > (Degrees)360)
        {
            throw "Degrees can not be larger than 360"; // TODO : throw class and more info
        }
    }
}
