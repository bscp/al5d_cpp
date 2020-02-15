
#ifndef AL5D_CPP_JOINT_HPP
#define AL5D_CPP_JOINT_HPP

// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/JointConfig.hpp>

namespace al5d
{
    typedef std::string Command;
    
    class Joint
    {
    public:
        explicit Joint(const JointConfig & config);

        virtual ~Joint() = default;
    
        std::string move_command_from_degrees(const Degrees &degrees) const;
        
        std::string move_command_from_pulse_width(const PulseWidth &pulse_width) const;
        
        std::string move_command_to_max() const;
        
        std::string move_command_to_min() const;
        
    private:
        bool can_reach_degrees(const Degrees &degrees) const;
        
        bool can_reach_pulse_width(const PulseWidth &pulse_width) const;
    
        PulseWidth to_pulse_width(Degrees degrees) const;
        
        BoardChannel board_channel;
        PulseWidth min_pulse_width;
        PulseWidth max_pulse_width;
        Degrees min_degrees;
        Degrees max_degrees;
        
        long degrees_range, pulse_width_range;
        double convert_ratio;
        bool reversed;
    };
}

#endif // AL5D_CPP_JOINT_HPP
