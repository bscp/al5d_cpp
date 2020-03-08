
// HEADER INCLUDE
#include <al5d_cpp/AL5D.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/communicators/ConsoleCommunicator.hpp>
#include <al5d_cpp/AL5D_logging.hpp>

namespace al5d
{
    /*static*/ AL5DPtr AL5D::as_pointer(
        const AL5DConfig& config)
    {
        return std::make_shared<AL5D>(config);
    }
    
    
    AL5D::AL5D(
        const AL5DConfig& al5d_config)
        : joints(construct_joints(al5d_config.joint_configs))
        , communicator_ptr(nullptr)
        , timer_ptr()
    {
    }
    
    
    AL5D::~AL5D()
    {
        disconnect(); // only so that it gets logged
    }
    
    
    Joints AL5D::construct_joints(const JointConfigs& joints_configs) const
    {
        Joints constructed_joints;
        
        for (const auto& joint_config : joints_configs)
        {
            const auto joint = Joint(joint_config);
            constructed_joints.push_back(joint);
        }
        
        return constructed_joints;
    }
    
    
    void AL5D::connect(
        const SerialPort& serial_port,
        const BaudRate& serial_baud)
    {
        log_connecting(serial_port, serial_baud);
        communicator_ptr = ConsoleCommunicator::as_pointer();
//        communicator_ptr = SerialCommunicator::as_pointer(serial_port, serial_baud);
    }
    
    
    void AL5D::disconnect()
    {
        log_disconnecting();
        communicator_ptr = nullptr;
    }
    
    
    void AL5D::transmit_command(
        const Command &command)
    const
    {
        validate_connection();
        communicator_ptr->transmit(command + "\r");
    }
    
    
    void AL5D::validate_connection()
    const
    {
        if (!is_connected())
        {
            log_no_serial_connection();
            throw std::invalid_argument("No connection connection established");
        }
    }
    
    
    bool AL5D::is_connected()
    const
    {
        return communicator_ptr != nullptr;
    }
    
    
    bool AL5D::is_moving() const
    {
        if (timer_ptr == nullptr)
        {
            return false;
        }
        
        return !timer_ptr->has_elapsed();
    }
    
    
    const Joint &AL5D::get_joint(
        const JointType &joint_type)
    const
    {
        return joints.at(joint_type);
    }
    
    
    void AL5D::start_timer(long duration)
    {
        timer_ptr = Timer::as_pointer(duration);
    }
    
    
    void AL5D::move_to(
        const JointTypeAngles &joint_type_angles)
    {
        log_moving_joints(joint_type_angles);
        transmit_command(get_move_command(joint_type_angles));
        start_timer(DURATION);
    }
    
    
    void AL5D::move_to(
        const JointTypeAngle &joint_type_angle)
    {
        log_moving_joint(joint_type_angle);
        transmit_command(get_move_command(joint_type_angle));
        start_timer(DURATION);
    }
    
    
    void AL5D::move_to(
        const JointTypeAngles &joint_type_angles,
        const Duration &move_duration)
    {
        log_moving_joints(joint_type_angles, move_duration);
        transmit_command(get_move_command(joint_type_angles, move_duration));
        start_timer(move_duration.in_milliseconds());
    }
    
    
    void AL5D::move_to(
        const JointTypeAngle &joint_type_angle,
        const Duration &move_duration)
    {
        log_moving_joint(joint_type_angle, move_duration);
        transmit_command(get_move_command(joint_type_angle, move_duration));
        start_timer(move_duration.in_milliseconds());
    }
    
    
    Command AL5D::get_move_command(
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
    
    
    Command AL5D::get_move_command(
        const JointTypeAngles &joint_type_angles,
        const Duration &move_duration)
    const
    {
        Command command = get_move_command(joint_type_angles);
        command += "T" + std::to_string(move_duration.in_milliseconds());
        return command;
    }
    
    
    Command AL5D::get_move_command(
        const JointTypeAngle &joint_type_angle)
    const
    {
        const auto &joint_type = joint_type_angle.joint_type;
        const auto &joint_angle = joint_type_angle.joint_angle;
        const auto &joint = get_joint(joint_type);
        return joint.get_move_command(joint_angle);
    }
    
    
    Command AL5D::get_move_command(
        const JointTypeAngle &joint_type_angle,
        const Duration &move_duration)
    const
    {
        const auto command = get_move_command(joint_type_angle);
        const auto milliseconds = move_duration.in_milliseconds();
        return command + "T" + std::to_string(milliseconds);
    }
    
    
    JointTypeAngle AL5D::angle_from_degrees(
        JointType joint_type,
        Degrees degrees)
    const
    {
        const auto& joint = get_joint(joint_type);
        const auto joint_angle = joint.angle_from_degrees(degrees);
        return {joint_type, joint_angle};
    }
    
    
    JointTypeAngle AL5D::angle_from_pulse_width(
        JointType joint_type,
        PulseWidth  pulse_width)
    const
    {
        const auto& joint = get_joint(joint_type);
        const auto joint_angle = joint.angle_from_pulse_width(pulse_width);
        return {joint_type, joint_angle};
    }
    
    
    void AL5D::do_emergency_stop() const
    {
        log_emergency_stop();
        transmit_command(get_emergency_stop_command());
    }
    
    
    std::string AL5D::get_emergency_stop_command() const
    {
        return "STOP";
    }
}
