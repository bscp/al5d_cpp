// HEADER INCLUDE
#include <al5d_cpp/base/Joint.hpp>

// SYSTEM INCLUDES
#include <stdexcept>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>


namespace al5d
{
    Joint::Joint(const JointConfig &joint_config)
        : Joint(
            joint_config.board_channel,
            joint_config.min_pulse_width,
            joint_config.max_pulse_width,
            joint_config.min_degrees,
            joint_config.max_degrees)
    {
    }
    
    
    Joint::Joint(BoardChannel board_channel,
                 PulseWidth min_pulse_width,
                 PulseWidth max_pulse_width,
                 Degrees min_degrees,
                 Degrees max_degrees)
        : board_channel(board_channel)
        , min_pulse_width(min_pulse_width)
        , max_pulse_width(max_pulse_width)
        , min_degrees(min_degrees)
        , max_degrees(max_degrees)
    {
        lowest_degrees = min_degrees <= max_degrees ? min_degrees : max_degrees;
        highest_degrees = min_degrees <= max_degrees ? max_degrees : min_degrees;
        degrees_range = max_degrees - min_degrees;
        pulse_width_range = max_pulse_width - min_pulse_width;
        convert_ratio = double(pulse_width_range) / double(degrees_range);
    }
    
    
    std::string Joint::get_move_command(
        const JointAngle& joint_angle)
        const
    {
        validate_pulse_width(joint_angle);
        return create_move_command(joint_angle);
    }
    
    
    std::string Joint::create_move_command(
        const JointAngle& joint_angle)
        const
    {
        const auto board_channel_string = std::to_string(board_channel);
        const auto pulse_width_string = std::to_string(joint_angle);
        return "#" + board_channel_string + "P" + pulse_width_string;
    }
    
    
    JointAngle Joint::angle_from_degrees(Degrees degrees) const
    {
        validate_degrees(degrees);
        return JointAngle((degrees - min_degrees) * convert_ratio + min_pulse_width);
    }
    
    
    JointAngle Joint::angle_from_pulse_width(PulseWidth pulse_width) const
    {
        validate_pulse_width(pulse_width);
        return pulse_width;
    }
    
    
    bool Joint::can_reach_pulse_width(const PulseWidth &pulse_width) const
    {
        bool above_lower_bound = min_pulse_width <= pulse_width;
        bool below_upper_bound = pulse_width <= max_pulse_width;
        return above_lower_bound && below_upper_bound;
    }
    
    
    bool Joint::can_reach_degrees(const Degrees &degrees) const
    {
        bool above_lower_bound = lowest_degrees <= degrees;
        bool below_upper_bound = degrees <= highest_degrees;
        return above_lower_bound && below_upper_bound;
    }
    
    
    void Joint::validate_pulse_width(PulseWidth pulse_width) const
    {
        if (!can_reach_pulse_width(pulse_width))
        {
            LOG_ERROR("pulse_width out of range");
            throw std::invalid_argument("pulse_width out of range");
        }
    }
    
    
    void Joint::validate_degrees(Degrees degrees) const
    {
        if (!can_reach_degrees(degrees))
        {
            LOG_ERROR("degrees out of range");
            throw std::invalid_argument("degrees out of range");
        }
    }
}
