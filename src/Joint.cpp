
// HEADER INCLUDE
#include <al5d_cpp/Joint.hpp>

// SYSTEM INCLUDES
#include <stdexcept>

namespace al5d
{
    Joint::Joint(const JointConfig &config)
        : board_channel(config.board_channel)
        , min_pulse_width(config.min_pulse_width)
        , max_pulse_width(config.max_pulse_width)
        , min_degrees(config.min_degrees)
        , max_degrees(config.max_degrees)
    {
        degrees_range = max_degrees - min_degrees;
        pulse_width_range = max_pulse_width - min_pulse_width;
        convert_ratio = double(pulse_width_range) / double(degrees_range);
        reversed = false;
    }
    
    
    std::string Joint::move_command_from_pulse_width(const PulseWidth &pulse_width) const
    {
        if (!can_reach_pulse_width(pulse_width))
        {
            throw std::invalid_argument("joint " + std::to_string(board_channel) + " can not reach " + std::to_string(pulse_width) + " pwm"); // TODO
        }
        
        return "#" + std::to_string(board_channel) + "P" + std::to_string(pulse_width);
    }
    
    
    std::string Joint::move_command_from_degrees(const Degrees &degrees) const
    {
        if (!can_reach_degrees(degrees))
        {
            throw std::invalid_argument("joint <channel> can not reach <degrees> degrees"); // TODO
        }
        
        PulseWidth pulse_width = to_pulse_width(degrees);
        return move_command_from_pulse_width(pulse_width);
    }
    
    
    std::string Joint::move_command_to_max() const
    {
        Command command = "#" + std::to_string(board_channel);
        return command + "P" + std::to_string(max_pulse_width);
    }
    
    
    std::string Joint::move_command_to_min() const
    {
        Command command = "#" + std::to_string(board_channel);
        return command + "P" + std::to_string(min_pulse_width);
    }
    
    
    bool Joint::can_reach_pulse_width(const PulseWidth &pulse_width) const
    {
        bool above_lower_bound = min_pulse_width <= pulse_width;
        bool below_upper_bound = pulse_width <= max_pulse_width;
        return above_lower_bound && below_upper_bound;
    }
    
    
    bool Joint::can_reach_degrees(const Degrees &degrees) const
    {
        bool above_lower_bound = min_degrees <= degrees;
        bool below_upper_bound = degrees <= max_degrees;
        return above_lower_bound && below_upper_bound;
    }
    
    
    PulseWidth Joint::to_pulse_width(Degrees degrees) const
    {
        if (reversed)
        {
            return max_pulse_width - (degrees - min_degrees) * convert_ratio;
        }
        else
        {
            return (degrees - min_degrees) * convert_ratio + min_pulse_width;
        }
    }
}
