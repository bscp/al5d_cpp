#ifndef AL5D_CPP_JOINT_HPP
#define AL5D_CPP_JOINT_HPP

// SYSTEM INCLUDES
#include <string>
#include <vector>
#include <functional>

// PROJECT INCLUDES
#include <al5d_cpp/base/JointConfig.hpp>
#include <al5d_cpp/base/JointAngle.hpp>
#include <al5d_cpp/base/Communicator.hpp>
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    typedef std::function<void(const std::string&)>
        Transmit;


    class JointBase
    {
    public:
        explicit JointBase(
            const JointConfig &joint_config);
        
        virtual ~JointBase() = default;

        void set_communicator_ptr(
        const CommunicatorPtr& communicator_ptr);
    
        void move_to(
            const Degrees& degrees)
            const;
        
    private:

        void validate_communicator_ptr()
            const;

        void transmit(
            const std::string& message)
            const;

        Degrees get_lowest_degrees()
            const;
        
        Degrees get_highest_degrees()
            const;
        
        void validate_degrees(
            Degrees degrees)
            const;
    
        bool can_reach_degrees(
            const Degrees &degrees)
            const;
        
        JointAngle to_pulse_width(
            Degrees degrees)
            const;
        
        std::string joint_name;
        JointType joint_type;
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

        CommunicatorPtr communicator_ptr;
    };
    
    typedef std::vector<JointBase> JointBases;
}


#endif // AL5D_CPP_JOINT_HPP
