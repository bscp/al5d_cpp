#ifndef AL5D_CPP_JOINTBASECONFIG_HPP
#define AL5D_CPP_JOINTBASECONFIG_HPP

// SYSTEM INCLUDES
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d_cpp
{
    struct JointBaseConfig
    {
        JointBaseConfig(
            const JointName& name,
            const JointType& type,
            const BoardChannel& board_channel,
            const PulseWidthRange& pulse_width_range,
            const DegreeRange &degree_range);
        
        const JointName name;
        const JointType type;
        const BoardChannel board_channel;
        const PulseWidthRange pulse_width_range;
        const DegreeRange degree_range;
    
    private:
        
        void validate_board_channel()
            const;
    };
    
    typedef std::vector<JointBaseConfig> JointBaseConfigs;
}


#endif // AL5D_CPP_JOINTBASECONFIG_HPP
