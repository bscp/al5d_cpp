#ifndef AL5D_CPP_COMMAND_HPP
#define AL5D_CPP_COMMAND_HPP

// SYSTEM INCLUDES
#include <memory>
#include <vector>


namespace al5d_cpp
{
    class Command
    {
    public:
        Command() {}

        virtual void execute() = 0;
    };

    typedef std::shared_ptr<Command> CommandPtr;
}


#endif // AL5D_CPP_COMMAND_HPP
