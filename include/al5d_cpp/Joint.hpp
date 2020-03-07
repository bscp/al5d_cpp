
#ifndef AL5D_CPP_JOINT_HPP
#define AL5D_CPP_JOINT_HPP

// SYSTEM INCLUDES
#include <string>
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/JointConfig.hpp>
#include <al5d_cpp/JointAngle.hpp>

namespace al5d
{
    typedef std::string Command;
    
    class Joint
    {
    public:
        explicit Joint(
            const JointConfig &joint_config);
    
        Joint(
            BoardChannel board_channel,
            PulseWidth min_pulse_width,
            PulseWidth max_pulse_width,
            Degrees min_degrees,
            Degrees max_degrees);
        virtual ~Joint() = default;
    
        std::string get_move_command(
            const JointAngle& joint_angle)
            const;
        
        JointAngle angle_from_degrees(
            Degrees degrees)
            const;
    
        JointAngle angle_from_pulse_width(
            PulseWidth pulse_width)
            const;
        
    private:
        
        void validate_degrees(
            Degrees degrees)
            const;
        
        void validate_pulse_width(
            PulseWidth pulse_width)
            const;
    
        bool can_reach_degrees(
            const Degrees &degrees)
            const;
    
        bool can_reach_pulse_width(
            const PulseWidth &pulse_width)
            const;
    
        std::string create_move_command(
            const JointAngle &joint_angle)
            const;
        
        BoardChannel board_channel;
        PulseWidth min_pulse_width;
        PulseWidth max_pulse_width;
        Degrees min_degrees;
        Degrees max_degrees;
        Degrees lowest_degrees;
        Degrees highest_degrees;
        
        long degrees_range;
        long pulse_width_range;
        double convert_ratio;
    };
    
    typedef std::vector<Joint> Joints;
}

#endif // AL5D_CPP_JOINT_HPP
