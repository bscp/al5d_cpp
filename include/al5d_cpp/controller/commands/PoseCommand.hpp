#ifndef AL5D_CPP_POSECOMMAND_HPP
#define AL5D_CPP_POSECOMMAND_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/ContextCommand.hpp>


namespace al5d
{
    class PoseCommand : public ContextCommand
    {
    public:

        static CommandPtr as_ptr(
            Controller* context_ptr);

        explicit PoseCommand(
            Controller* context_ptr);

        virtual ~PoseCommand() = default;

        void execute()
            override;
    };
}


#endif // AL5D_CPP_POSECOMMAND_HPP
