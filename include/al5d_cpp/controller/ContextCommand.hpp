#ifndef AL5D_CPP_CONTEXTCOMMAND_HPP
#define AL5D_CPP_CONTEXTCOMMAND_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/Command.hpp>
#include <al5d_cpp/controller/Controller.hpp>


namespace al5d
{
    class ContextCommand : public Command
    {
    public:
        explicit ContextCommand(
            Controller* context_ptr);

        virtual ~ContextCommand() = default;

        virtual void execute() = 0;
    
    protected:

        Controller* context_ptr; // TODO : make smart pointer
    };
}


#endif // AL5D_CPP_CONTEXTCOMMAND_HPP
