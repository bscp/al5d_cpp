// HEADER INCLUDE
#include <al5d_cpp/controller/commands/AnglesCommand.hpp>


namespace al5d
{
    /*static*/ CommandPtr AnglesCommand::as_pointer(
        Controller* context_ptr,
        const JointTypeAngles& joint_type_angles,
        const Duration& move_duration)
    {
        return std::make_shared<AnglesCommand>(
            context_ptr, joint_type_angles, move_duration);
    }


    AnglesCommand::AnglesCommand(
        Controller* context_ptr,
        const JointTypeAngles& joint_type_angles,
        const Duration& move_duration)
        : ContextCommand(context_ptr)
        , joint_type_angles({joint_type_angles})
        , move_duration(move_duration)
    {
    }

    
    void AnglesCommand::execute()
    {
        auto& al5d = context_ptr->get_al5d();
        al5d.move_to_angles(joint_type_angles, move_duration);
    }
}
