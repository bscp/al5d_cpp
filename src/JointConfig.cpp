
// HEADER INCLUDE
#include <al5d_cpp/JointConfig.hpp>

namespace al5d
{
    JointConfig::JointConfig(BoardChannel boardChannel, PulseWidth minPulseWidth,
                             PulseWidth maxPulseWidth, const Degrees &min_degrees,
                             const Degrees &max_degrees)
        : board_channel(boardChannel)
        , min_pulse_width(minPulseWidth)
        , max_pulse_width(maxPulseWidth)
        , min_degrees(min_degrees)
        , max_degrees(max_degrees)
    {
    }
}
