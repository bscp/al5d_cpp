// HEADER INCLUDE
#include <al5d_cpp/base/AL5DBase.hpp>


namespace al5d
{   
    AL5DBase::AL5DBase(
        const AL5DBaseConfig& config)
        : joints(construct_joints(config.joint_configs))
        , timer_ptr()
    {
    }
    
    
    AL5DBase::~AL5DBase()
    {
        // only so that it gets logged
        // communicator_ptr->disconnect(); // TODO : implement interface
    }
    
    
    Joints AL5DBase::construct_joints(
        const JointConfigs& joints_configs)
        const
    {
        Joints constructed_joints;
        
        for (const auto& joint_config : joints_configs)
        {
            const auto joint = Joint(joint_config);
            constructed_joints.push_back(joint);
        }
        
        return constructed_joints;
    }
    
    
    void AL5DBase::transmit_command(
        const Command &command)
    {
        transmit(command + "\r");
    }
    
    
    bool AL5DBase::is_moving()
        const
    {
        if (timer_ptr == nullptr)
        {
            return false;
        }
        
        return !timer_ptr->has_elapsed();
    }
    
    
    const Joint &AL5DBase::get_joint(
        const JointType &joint_type)
    const
    {
        return joints.at(joint_type);
    }
    
    
    void AL5DBase::start_timer(
        long duration)
    {
        timer_ptr = Timer::as_pointer(duration);
    }
    
    
    void AL5DBase::move_to(
        const JointTypeAngles &joint_type_angles)
    {
        transmit_command(get_move_command(joint_type_angles));
        start_timer(DURATION);
    }
    
    
    void AL5DBase::move_to(
        const JointTypeAngle &joint_type_angle)
    {
        transmit_command(get_move_command(joint_type_angle));
        start_timer(DURATION);
    }
    
    
    void AL5DBase::move_to(
        const JointTypeAngles &joint_type_angles,
        const Duration &move_duration)
    {
        transmit_command(get_move_command(joint_type_angles, move_duration));
        start_timer(move_duration.in_milliseconds());
    }
    
    
    void AL5DBase::move_to(
        const JointTypeAngle &joint_type_angle,
        const Duration &move_duration)
    {
        transmit_command(get_move_command(joint_type_angle, move_duration));
        start_timer(move_duration.in_milliseconds());
    }
    
    
    Command AL5DBase::get_move_command(
        const JointTypeAngles &joint_type_angles)
        const
    {
        Command command;
        
        for (const auto &joint_type_angle : joint_type_angles)
        {
            const auto &joint_type = joint_type_angle.joint_type;
            const auto &joint_angle = joint_type_angle.joint_angle;
            const auto &joint = get_joint(joint_type);
            command += joint.get_move_command(joint_angle);
        }
        
        return command;
    }
    
    
    Command AL5DBase::get_move_command(
        const JointTypeAngles &joint_type_angles,
        const Duration &move_duration)
        const
    {
        Command command = get_move_command(joint_type_angles);
        command += "T" + std::to_string(move_duration.in_milliseconds());
        return command;
    }
    
    
    Command AL5DBase::get_move_command(
        const JointTypeAngle &joint_type_angle)
        const
    {
        const auto &joint_type = joint_type_angle.joint_type;
        const auto &joint_angle = joint_type_angle.joint_angle;
        const auto &joint = get_joint(joint_type);
        return joint.get_move_command(joint_angle);
    }
    
    
    Command AL5DBase::get_move_command(
        const JointTypeAngle &joint_type_angle,
        const Duration &move_duration)
        const
    {
        const auto command = get_move_command(joint_type_angle);
        const auto milliseconds = move_duration.in_milliseconds();
        return command + "T" + std::to_string(milliseconds);
    }
    
    
    JointTypeAngle AL5DBase::angle_from_degrees(
        JointType joint_type,
        Degrees degrees)
        const
    {
        const auto& joint = get_joint(joint_type);
        const auto joint_angle = joint.angle_from_degrees(degrees);
        return {joint_type, joint_angle};
    }
    
    
    JointTypeAngle AL5DBase::angle_from_pulse_width(
        JointType joint_type,
        PulseWidth  pulse_width)
        const
    {
        const auto& joint = get_joint(joint_type);
        const auto joint_angle = joint.angle_from_pulse_width(pulse_width);
        return {joint_type, joint_angle};
    }
    
    
    void AL5DBase::do_emergency_stop()
    {
        auto command = get_emergency_stop_command();
        transmit_command(command);
    }
    
    
    std::string AL5DBase::get_emergency_stop_command()
        const
    {
        return "STOP";
    }
}
