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
    }
}
