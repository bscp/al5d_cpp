
#ifndef AL5D_CPP_JOINTCONFIG_HPP
#define AL5D_CPP_JOINTCONFIG_HPP

// SYSTEM INCLUDES
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/types.hpp>

namespace al5d
{
    struct JointConfig
    {
        JointConfig(
            const BoardChannel boardChannel,
            const PulseWidth minPulseWidth,
            const PulseWidth maxPulseWidth,
            const Degrees &min_degrees,
            const Degrees &max_degrees);

        BoardChannel board_channel;
        PulseWidth min_pulse_width;
        PulseWidth max_pulse_width;
        Degrees min_degrees;
        Degrees max_degrees;
    };
    
    typedef std::vector<JointConfig> JointConfigs;
}

#endif // AL5D_CPP_JOINTCONFIG_HPP
