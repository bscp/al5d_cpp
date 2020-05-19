// HEADER INCLUDE
#include <al5d_cpp/controller/commands/PoseCommand.hpp>


namespace al5d
{
    /*static*/ CommandPtr PoseCommand::as_ptr(
        Controller* context_ptr,
        const PoseName& pose_name,
        const Duration& move_duration)
    {
        return std::make_shared<PoseCommand>(
            context_ptr, pose_name, move_duration);
    }


    PoseCommand::PoseCommand(
        Controller* context_ptr,
        const PoseName& pose_name,
        const Duration& move_duration)
        : ContextCommand(context_ptr)
        , pose_name(pose_name)
        , move_duration(move_duration)
    {
    }

    
    void PoseCommand::execute()
    {
        auto& al5d = context_ptr->get_al5d();
        al5d.move_to_pose(pose_name, move_duration);
    }
}
