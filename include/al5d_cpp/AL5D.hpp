
#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// SYSTEM INCLUDES
#include <cstdint>
#include <vector>
#include <memory>

// PROJECT INCLUDES
#include <al5d_cpp/AL5DConfig.hpp>
#include <al5d_cpp/Duration.hpp>
#include <al5d_cpp/Joint.hpp>
#include <al5d_cpp/JointType.hpp>
#include <al5d_cpp/JointTypeAngle.hpp>
#include <al5d_cpp/communicators/Communicator.hpp>
#include <al5d_cpp/communicators/SerialCommunicator.hpp>
#include <al5d_cpp/Timer.hpp>

#define DURATION 3000 // in milliseconds

namespace al5d
{
    class AL5D;
    typedef std::shared_ptr<AL5D> AL5DPtr;
    
    class AL5D
    {
    public:
        static AL5DPtr as_pointer(
            const AL5DConfig& config);
        
        explicit AL5D(
            const AL5DConfig& al5d_config);
    
        virtual ~AL5D();
        
        JointTypeAngle angle_from_degrees(
            JointType joint_type,
            Degrees  degrees)
            const;

        JointTypeAngle angle_from_pulse_width(
            JointType joint_type,
            PulseWidth pulse_width)
            const;
    
        void connect(
            const SerialPort& serial_port,
            const BaudRate& serial_baud);
    
        void disconnect();
    
        bool is_connected()
            const;
        
        bool is_moving()
            const;
        
        void move_to(
            const JointTypeAngles &joint_type_angles);
//            const;
    
        void move_to(
            const JointTypeAngle &joint_type_angle);
//            const;
    
        void move_to(
            const JointTypeAngles &joint_type_angles,
            const Duration &move_duration);
//            const;
    
        void move_to(
            const JointTypeAngle &joint_type_angle,
            const Duration &move_duration);
//            const;
    
        void do_emergency_stop()
            const;
        
    private:
        Joints construct_joints(
            const JointConfigs &joints_configs)
            const;
        
        void start_timer(
            long duration);
        
        void transmit_command(
            const Command &command)
            const;

        const Joint &get_joint(
            const JointType &joint_type)
            const;
        
        Command get_move_command(
            const JointTypeAngles &joint_type_angles,
            const Duration &move_duration)
            const;
        
        Command get_move_command(
            const JointTypeAngles &joint_type_angles)
            const;
        
        Command get_move_command(
            const JointTypeAngle &joint_type_angle,
            const Duration &move_duration)
            const;
        
        Command get_move_command(
            const JointTypeAngle &joint_type_angle)
            const;
        
        std::string get_emergency_stop_command()
            const;
    
        void validate_connection()
            const;
        
        const Joints joints;
        CommunicatorPtr communicator_ptr;
        TimerPtr timer_ptr;
    };
}

#endif // AL5D_CPP_AL5D_HPP
