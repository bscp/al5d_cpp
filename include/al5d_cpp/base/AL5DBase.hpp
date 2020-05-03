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
#include <al5d_cpp/base/JointConfig.hpp>
#include <al5d_cpp/base/AL5DBaseConfig.hpp>


namespace al5d
{
    class AL5DBase : public ICommunicator
    {
    public:
        typedef AL5DBaseConfig Config;
    
        virtual ~AL5DBase();
        
        JointTypeAngle angle_from_degrees(
            JointType joint_type,
            Degrees  degrees)
            const;

        JointTypeAngle angle_from_pulse_width(
            JointType joint_type,
            PulseWidth pulse_width)
            const;
        
        virtual void move_to(
            const JointTypeAngles &joint_type_angles);
    
        virtual void move_to(
            const JointTypeAngle &joint_type_angle);
    
        virtual void move_to(
            const JointTypeAngles &joint_type_angles,
            const Duration &move_duration);
    
        virtual void move_to(
            const JointTypeAngle &joint_type_angle,
            const Duration &move_duration);
    
        virtual void do_emergency_stop();
        
        virtual void transmit_command(
            const Command &command);
        
    protected:

        explicit AL5DBase(
            const AL5DBaseConfig& config);

        void transmit(const std::string& message)
            override                                              
        
        {
            // throw "Not implemented";
        }

    private:
    
        static Joints construct_joints(
            const JointConfigs &joints_configs);

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
        
        static Command get_emergency_stop_command();
        
        const Joints joints;
    };
}


#endif // AL5D_CPP_AL5DBASE_HPP
