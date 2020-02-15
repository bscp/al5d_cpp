
#ifndef AL5D_CPP_JOINTCONFIG_HPP
#define AL5D_CPP_JOINTCONFIG_HPP

// PROJECT INCLUDES
#include <al5d_cpp/types.hpp>

namespace al5d
{
    struct JointConfig
    {
        JointConfig(BoardChannel boardChannel, PulseWidth minPulseWidth, PulseWidth maxPulseWidth,
                    const Degrees &min_degrees, const Degrees &max_degrees);

        BoardChannel board_channel;
        PulseWidth min_pulse_width;
        PulseWidth max_pulse_width;
        Degrees min_degrees;
        Degrees max_degrees;
    };
}

#endif // AL5D_CPP_JOINTCONFIG_HPP
