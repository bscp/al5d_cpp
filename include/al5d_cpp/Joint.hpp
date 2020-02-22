
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
        static Joint from_config(
            const JointConfig &joint_config);
        
        virtual ~Joint() = default;
    
        std::string get_move_command(
            const JointAngle& joint_angle)
            const;
        
        JointAngle get_angle_from_degrees(
            Degrees degrees)
            const;
    
        JointAngle get_angle_from_pulse_width(
            PulseWidth pulse_width)
            const;
        
    private:
        Joint(
            BoardChannel board_channel,
            PulseWidth min_pulse_width,
            PulseWidth max_pulse_width,
            Degrees min_degrees,
            Degrees max_degrees);
        
        bool __can_reach_degrees(
            const Degrees &degrees)
            const;
        
        bool __can_reach_pulse_width(
            const PulseWidth &pulse_width)
            const;
        
        void __validate_degrees(
            Degrees degrees)
            const;
        
        void __validate_pulse_width(
            PulseWidth pulse_width)
            const;
    
        std::string __create_move_command(
            const JointAngle &joint_angle)
            const;
        
        BoardChannel board_channel;
        PulseWidth min_pulse_width;
        PulseWidth max_pulse_width;
        Degrees min_degrees;
        Degrees max_degrees;
        
        long degrees_range;
        long pulse_width_range;
        double convert_ratio;
    };
    
    typedef std::vector<Joint> Joints;
}

#endif // AL5D_CPP_JOINT_HPP
