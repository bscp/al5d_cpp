
// HEADER INCLUDE
#include <al5d_cpp/AL5D.hpp>

namespace al5d
{
    AL5D::AL5D(CommunicatorPtr communicator_ptr, JointMap joints)
        : joints(std::move(joints))
        , communicator_ptr(std::move(communicator_ptr))
    {
    }
    
    
    void AL5D::stop() const
    {
        transmit("STOP\r");
    }
    
    
    void AL5D::transmit(const Command &command) const
    {
        if (communicator_ptr != nullptr)
        {
            communicator_ptr->transmit(command);
        }
    }
    
    
    const Joint &AL5D::get_joint(const JointId &joint_id) const
    {
        return joints.at(joint_id);
    }
    
    
    void AL5D::move_to_pulse_widths(const JointPulseWidthMap &joint_pulse_widths) const
    {
        Command command;
    
        for (const auto &joint_pulse_width_goal : joint_pulse_widths)
        {
            const auto &joint_type = joint_pulse_width_goal.first;
            const auto &joint = get_joint(joint_type);
            const auto &pulse_width = joint_pulse_width_goal.second;
            command += joint.move_command_from_pulse_width(pulse_width);
        }
    
        transmit(command + "\r");
    }
    
    
    void AL5D::move_to_degrees(const JointDegreesMap &join_degrees) const
    {
        Command command;
    
        for (const auto &joint_degree : join_degrees)
        {
            const auto &joint_id = joint_degree.first;
            const auto &joint = get_joint(joint_id);
            const auto &degree = joint_degree.second;
            command += joint.move_command_from_degrees(degree);
        }
    
        transmit(command + "\r");
    }
}
