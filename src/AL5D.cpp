
// HEADER INCLUDE
#include <al5d_cpp/AL5D.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/communicators/ConsoleCommunicator.hpp>

namespace al5d
{
    /* static */ AL5D AL5D::from_default_config()
    {
        log_constructing();
        return AL5D(AL5D::__get_default_config());
    }

    
    /*static*/ AL5DConfig AL5D::__get_default_config()
    {
        return AL5DConfig({
            JointConfig({0, 500, 2500, -90,  90}), // BASE_JOINT
            JointConfig({1, 500, 2500, -30,  90}), // SHOULDER_JOINT
            JointConfig({2, 500, 2500,   0, 135}), // ELBOW_JOINT
            JointConfig({3, 500, 2500, -90,  90}), // WRIST_JOINT
            JointConfig({4, 500, 2500, -90,  90}), // WRIST_ROTATE_JOINT
            JointConfig({5, 500, 2500,   0,   1}), // GRIPPER_JOINT
        });
    }


    AL5D::AL5D(const AL5DConfig& al5d_config)
        : joints(__construct_joints(al5d_config.joint_configs))
        , communicator_ptr(nullptr)
    {
    }
    
    
    AL5D::~AL5D()
    {
        disconnect(); // for logging purposes
    }


    Joints AL5D::__construct_joints(const JointConfigs& joints_configs) const
    {
        Joints constructed_joints;
        
        for (const auto& joint_config : joints_configs)
        {
            const auto joint = Joint::from_config(joint_config);
            constructed_joints.push_back(joint);
        }
        
        return constructed_joints;
    }


    void AL5D::connect(
        const std::string &serial_port,
        long serial_baudrate)
    {
        log_connecting(serial_port, serial_baudrate);
        communicator_ptr = std::make_shared<ConsoleCommunicator>();
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
        if (communicator_ptr == nullptr)
        {
            log_no_serial_connection();
            throw std::invalid_argument("No serial connection established");
        }
    }


    const Joint &AL5D::__get_joint(
        const JointType &joint_type)
        const
    {
        return joints.at(joint_type);
    }
    
    
    void AL5D::start_moving_joints(
        const JointTypeAngles &joint_type_angles)
        const
    {
        log_moving_joints(joint_type_angles);
        transmit_command(get_move_command(joint_type_angles));
    }


    void AL5D::start_moving_joint(
        const JointTypeAngle &joint_type_angle)
        const
    {
        log_moving_joint(joint_type_angle);
        transmit_command(get_move_command(joint_type_angle));
    }
    
    
    void AL5D::start_moving_joints(const JointTypeAngles &joint_type_angles,
                                   const Duration &move_duration) const
    {
        log_moving_joints(joint_type_angles, move_duration);
        transmit_command(get_move_command(joint_type_angles, move_duration));
    }
    
    
    void AL5D::start_moving_joint(const JointTypeAngle &joint_type_angle,
                                  const Duration &move_duration) const
    {
        log_moving_joint(joint_type_angle, move_duration);
        transmit_command(get_move_command(joint_type_angle, move_duration));
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
            const auto &joint = __get_joint(joint_type);
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
        command += "S" + std::to_string(move_duration.in_milliseconds());
        return command;
    }
    
    
    Command AL5D::get_move_command(
        const JointTypeAngle &joint_type_angle)
        const
    {
        const auto &joint_type = joint_type_angle.joint_type;
        const auto &joint_angle = joint_type_angle.joint_angle;
        const auto &joint = __get_joint(joint_type);
        return joint.get_move_command(joint_angle);
    }
    
    
    Command AL5D::get_move_command(
        const JointTypeAngle &joint_type_angle,
        const Duration &move_duration)
        const
    {
        const auto command = get_move_command(joint_type_angle);
        const auto milliseconds = move_duration.in_milliseconds();
        return command + "S" + std::to_string(milliseconds);
    }
    
    
    JointTypeAngle AL5D::joint_angle_from_degrees(
        JointType joint_type,
        int degrees)
        const
    {
        const auto& joint = __get_joint(joint_type);
        const auto joint_angle = joint.get_angle_from_degrees(degrees);
        return {joint_type, joint_angle};
    }
    
    
    JointTypeAngle AL5D::joint_angle_from_pulse_width(
        JointType joint_type,
        int pulse_width)
        const
    {
        const auto& joint = __get_joint(joint_type);
        const auto joint_angle = joint.get_angle_from_pulse_width(pulse_width);
        return {joint_type, joint_angle};
    }
    
    
    void AL5D::do_emergency_stop() const
    {
        log_emergency_stop();
        transmit_command(__get_emergency_stop_command());
    }
    
    
    std::string AL5D::__get_emergency_stop_command() const
    {
        return "STOP";
    }
}
