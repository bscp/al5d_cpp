// HEADER INCLUDE
#include <al5d_cpp/controller/commands/PoseCommand.hpp>


namespace al5d
{
    /*static*/ CommandPtr PoseCommand::as_ptr(
        Controller* context_ptr)
    {
        return std::make_shared<PoseCommand>(context_ptr);
    }


    PoseCommand::PoseCommand(
        Controller* context_ptr)
        : ContextCommand(context_ptr)
    {
    }

    
    void PoseCommand::execute()
    {
        context_ptr->execute_pose_command();
    }
}
