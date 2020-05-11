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
            const JointName& name,
            const JointType& type,
            const BoardChannel& board_channel,
            const PulseWidthRange& pulse_width_range,
            const DegreesRange &degrees_range);
        
        void validate_board_channel_value(
            BoardChannel board_channel)
            const;
        
        const JointName name;
        const JointType type;
        const BoardChannel board_channel;
        const PulseWidthRange pulse_width_range;
        const DegreesRange degrees_range;
    };
    
    typedef std::vector<JointConfig> JointConfigs;
}


#endif // AL5D_CPP_JOINTCONFIG_HPP
