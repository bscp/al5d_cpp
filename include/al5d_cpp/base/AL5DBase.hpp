#ifndef AL5D_CPP_AL5DBASE_HPP
#define AL5D_CPP_AL5DBASE_HPP

// SYSTEM INCLUDES
#include <cstdint>
#include <vector>
#include <memory>

// PROJECT INCLUDES
#include <al5d_cpp/Duration.hpp>
#include <al5d_cpp/base/Joint.hpp>
#include <al5d_cpp/base/JointType.hpp>
#include <al5d_cpp/base/JointTypeAngle.hpp>
#include <al5d_cpp/interfaces/ICommunicator.hpp>
#include <al5d_cpp/Timer.hpp>
#include <al5d_cpp/base/JointConfig.hpp>
#include <al5d_cpp/base/AL5DBaseConfig.hpp>

#define DURATION 3000 // in milliseconds


namespace al5d
{
    

    class AL5DBase : public ICommunicator
    {
    public:
        typedef AL5DBaseConfig Config;
        
        explicit AL5DBase( // TODO : set as protected
            const AL5DBaseConfig& config);
    
        virtual ~AL5DBase();
        
        JointTypeAngle angle_from_degrees(
            JointType joint_type,
            Degrees  degrees)
            const;

        JointTypeAngle angle_from_pulse_width(
            JointType joint_type,
            PulseWidth pulse_width)
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
    
        void do_emergency_stop();
        
    protected:
        virtual void transmit(const std::string& message) = 0;

    private:
        Joints construct_joints(
            const JointConfigs &joints_configs)
            const;
        
        void start_timer(
            long duration);
        
        void transmit_command(
            const Command &command);

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
        
        const Joints joints;
        TimerPtr timer_ptr; // TODO : implement as mixin ?
    };
}

#endif // AL5D_CPP_AL5DBASE_HPP
