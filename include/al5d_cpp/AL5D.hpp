
#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// SYSTEM INCLUDES
#include <cstdint>
#include <vector>

// PROJECT INCLUDES
#include <al5d_cpp/Communicator.hpp>
#include <al5d_cpp/Joint.hpp>
#include <al5d_cpp/JointType.hpp>
#include <al5d_cpp/JointTypeAngle.hpp>
#include <al5d_cpp/communicators/SerialCommunicator.hpp>
#include <al5d_cpp/AL5DConfig.hpp>
#include <al5d_cpp/Duration.hpp>

namespace al5d
{
    class AL5D
    {
    public:
        static AL5D from_default_config();
        
        virtual ~AL5D();
        
        JointTypeAngle joint_angle_from_degrees(
            JointType joint_type,
            int degrees)
            const;

        JointTypeAngle joint_angle_from_pulse_width(
            JointType joint_type,
            int pulse_width)
            const;
    
        void connect(
            const std::string &serial_port,
            long serial_baudrate);
    
        void disconnect();
        
        void start_moving_joints(
            const JointTypeAngles &joint_type_angles)
            const;
    
        void start_moving_joint(
            const JointTypeAngle &joint_type_angle)
            const;
    
        void start_moving_joints(
            const JointTypeAngles &joint_type_angles,
            const Duration &move_duration)
            const;
    
        void start_moving_joint(
            const JointTypeAngle &joint_type_angle,
            const Duration &move_duration)
            const;
    
        void do_emergency_stop()
            const;
        
    private:
        static AL5DConfig __get_default_config();
        
        explicit AL5D(
            const AL5DConfig& al5d_config);
    
        Joints __construct_joints(
            const JointConfigs &joints_configs)
            const;
        
        void transmit_command(
            const Command &command)
            const;

        const Joint &__get_joint(
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
        
        std::string __get_emergency_stop_command()
            const;
    
        void validate_connection()
            const;
        
        const Joints joints;
        CommunicatorPtr communicator_ptr;
    };
    
     void log_moving_joint(
        const JointTypeAngle &joint_type_angle);
    
     void log_moving_joint(
        const JointTypeAngle &joint_type_angle,
        const Duration &duration);
    
     void log_moving_joints(
        const JointTypeAngles &joint_type_angles);
    
     void log_moving_joints(
        const JointTypeAngles &joint_type_angles,
        const Duration &duration);
    
     std::string get_moving_joint_log(
        const JointTypeAngle &joint_type_angle);
    
     std::string get_moving_joint_log(
        const JointTypeAngle &joint_type_angle,
        const Duration &duration);
    
     std::string get_connecting_log(
        const std::string &serial_port,
        long serial_baudrate);
    
     void log_connecting(
        const std::string &serial_port,
        long serial_baudrate);
    
     void log_constructing();
    
    void log_emergency_stop();
    
    void log_no_serial_connection();
    
     void log_disconnecting();
    
     std::string get_disconnecting_log();
}

#endif // AL5D_CPP_AL5D_HPP
