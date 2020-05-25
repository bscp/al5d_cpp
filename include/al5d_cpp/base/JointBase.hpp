#ifndef AL5D_CPP_JOINTBASE_HPP
#define AL5D_CPP_JOINTBASE_HPP

// SYSTEM INCLUDES
#include <string>
#include <vector>
#include <functional>

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/JointBaseConfig.hpp>
#include <al5d_cpp/base/CommunicatorBase.hpp>
#include <al5d_cpp/base/types.hpp>


namespace al5d_cpp
{
    class JointBase
    {
    public:
        explicit JointBase(
            const JointBaseConfig &joint_config);
        
        void move_to_angle(
            const Angle& angle)
            const;
    
        void move_to_angle(
            const Angle& angle,
            const Duration& move_duration)
            const;
        
        void stop()
            const;

        bool has_name(
            const JointName &name)
            const;

        bool has_type(
            const JointType &type)
            const;

        JointType get_type()
            const;

        void set_communicator_ptr(
            const CommunicatorBasePtr& communicator_ptr);
        
    private:

        void validate_communicator_ptr__()
            const;
        
        void validate_reachability__(
            const Angle& angle)
            const;

        void transmit_pulse_width__(
            const PulseWidth& pulse_width)
            const;

        void transmit_move_duration__(
            const Duration& move_duration)
            const;

        void transmit__(
            const ProtocolCommand& message)
            const;

        double calculate_convert_ratio__()
            const;
        
        PulseWidth to_pulse_width__(
            const Angle& angle)
            const;
        

        void log_moving__(
            const Angle& angle,
            const PulseWidth& pulse_width)
            const;

        void log_moving__(
            const Angle& angle,
            const PulseWidth& pulse_width,
            const Duration &move_duration)
            const;

        std::string get_log_moving__(
            const Angle& angle,
            const PulseWidth& pulse_width)
            const;

        std::string get_log_moving__(
            const Angle& angle,
            const PulseWidth& pulse_width,
            const Duration &duration)
            const;
        
        std::string name__;
        JointType type__;
        BoardChannel board_channel__;
        
        DegreeRange degree_range__;
        PulseWidthRange pulse_width_range__;
        double convert_ratio__;

        CommunicatorBasePtr communicator_ptr__;
    };
    
    typedef std::vector<JointBase> JointBases;
}


#endif // AL5D_CPP_JOINTBASE_HPP
