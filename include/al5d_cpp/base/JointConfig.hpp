#ifndef AL5D_CPP_JOINTCONFIG_HPP
#define AL5D_CPP_JOINTCONFIG_HPP

// SYSTEM INCLUDES
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    struct JointConfig
    {
        JointConfig(
            const BoardChannel& boardChannel,
            const PulseWidth& minPulseWidth,
            const PulseWidth& maxPulseWidth,
            const Degrees &min_degrees,
            const Degrees &max_degrees);
        
        void validate_board_channel_value(
            BoardChannel board_channel)
            const;
        
        void validate_pulse_width_value(
            PulseWidth pulse_width)
            const;
        
        void validate_degrees_value(
            Degrees degrees)
            const;

        const BoardChannel board_channel;
        const PulseWidth min_pulse_width;
        const PulseWidth max_pulse_width;
        const Degrees min_degrees;
        const Degrees max_degrees;
    };
    
    typedef std::vector<JointConfig> JointConfigs;
}


#endif // AL5D_CPP_JOINTCONFIG_HPP
