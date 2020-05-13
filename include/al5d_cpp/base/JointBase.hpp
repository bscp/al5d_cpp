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
#include <al5d_cpp/Duration.hpp>


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

        JointType get_type()
            const;

        bool has_type(
            const JointType &type)
            const;

        void set_communicator_ptr(
            const CommunicatorPtr& communicator_ptr);
    
        void move_to(
            const Degree& degree)
            const;
    
        void move_to(
            const Degree& degree,
            const Duration& move_duration)
            const;
        
    private:

        void __transmit_degree(
            const Degree& degree)
            const;

        void __transmit_move_duration(
            const Duration& duration)
            const;

        void __transmit(
            const std::string& message)
            const;

        double get_convert_ratio()
            const;

        void validate_communicator_ptr()
            const;

        Degree get_lowest_degree()
            const;
        
        Degree get_highest_degree()
            const;
        
        void validate_reachability(
            Degree degree)
            const;
        
        PulseWidth to_pulse_width(
            Degree degree)
            const;
        
        std::string name;
        JointType type;
        BoardChannel board_channel;
        
        DegreeRange degree_range;
        PulseWidthRange pulse_width_range;
        double convert_ratio;

        CommunicatorPtr communicator_ptr;
    };
    
    typedef std::vector<JointBase> JointBases;
}


#endif // AL5D_CPP_JOINT_HPP
