// HEADER INCLUDE
#include <al5d_cpp/controller/ContextCommand.hpp>


namespace al5d
{
    ContextCommand::ContextCommand(
        Controller* context_ptr)
        : Command()
        , context_ptr(context_ptr)
    {
    }
}
