#ifndef AL5D_CPP_JOINT_HPP
#define AL5D_CPP_JOINT_HPP

// SYSTEM INCLUDES
#include <string>
#include <vector>
#include <functional>

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/JointConfig.hpp>
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

        bool has_name(
            const JointName &name)
            const;

        bool has_type(
            const JointType &type)
            const;

        void set_communicator_ptr(
            const CommunicatorPtr& communicator_ptr);
    
        void move_to(
            const Degrees& degrees)
            const;
        
    private:

        double get_convert_ratio()
            const;

        void validate_communicator_ptr()
            const;

        void transmit(
            const std::string& message)
            const;

        Degrees get_lowest_degrees()
            const;
        
        Degrees get_highest_degrees()
            const;
        
        void validate_reachability(
            Degrees degrees)
            const;
        
        PulseWidth to_pulse_width(
            Degrees degrees)
            const;
        
        std::string name;
        JointType type;
        BoardChannel board_channel;
        
        DegreesRange degrees_range;
        PulseWidthRange pulse_width_range;
        double convert_ratio;

        CommunicatorPtr communicator_ptr;
    };
    
    typedef std::vector<JointBase> JointBases;
}


#endif // AL5D_CPP_JOINT_HPP
