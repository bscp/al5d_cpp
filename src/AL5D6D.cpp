
// HEADER INCLUDE
#include <al5d_cpp/AL5D6D.hpp>

// SYSTEM INCLUDES
#include <utility>

// PROJECT INCLUDES
#include <al5d_cpp/communicators/ConsoleCommunicator.hpp>

namespace al5d
{
    AL5D6D::AL5D6D(const SerialPort &serial_port, const AL5D6DConfig &config)
//        : AL5D6D(std::make_shared<SerialCommunicator>(serial_port, BAUD_9600), config) // TODO
        : AL5D6D(std::make_shared<ConsoleCommunicator>(), config)
    {
    }


    AL5D6D::AL5D6D(CommunicatorPtr communicator_ptr, const AL5D6DConfig &config)
        : AL5D(std::move(communicator_ptr), create_joint_map(config))
    {
    }
    
    
    AL5D::JointMap AL5D6D::create_joint_map(const AL5D6DConfig &config) const
    {
        return {
            {JOINT_BASE, Joint(config.base_joint_config)},
            {JOINT_SHOULDER, Joint(config.shoulder_joint_config)},
            {JOINT_ELBOW, Joint(config.elbow_joint_config)},
            {JOINT_WRIST, Joint(config.wrist_joint_config)},
            {JOINT_WRIST_ROTATE, Joint(config.wrist_rotate_joint_config)},
            {JOINT_GRIPPER, Joint(config.gripper_joint_config)},
        };
    }
    
    
    void AL5D6D::open_gripper()
    {
        const auto &gripper_joint = get_joint(JOINT_GRIPPER);
        Command command = gripper_joint.move_command_to_max();
        transmit(command + "\r");
    }
    
    
    void AL5D6D::close_gripper()
    {
        const auto &gripper_joint = get_joint(JOINT_GRIPPER);
        Command command = gripper_joint.move_command_to_min();
        transmit(command + "\r");
    }
}
