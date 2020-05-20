#ifndef AL5D_CPP_POSECOMMAND_HPP
#define AL5D_CPP_POSECOMMAND_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/ContextCommand.hpp>


namespace al5d_cpp
{
    class PoseCommand : public ContextCommand
    {
    public:

        static CommandPtr as_pointer(
            Controller* context_ptr,
            const PoseName& pose_name,
            const Duration& move_duration);

        explicit PoseCommand(
            Controller* context_ptr,
            const PoseName& pose_name,
            const Duration& move_duration);

        virtual ~PoseCommand() = default;

        void execute()
            override;

    private:

        PoseName pose_name;
        Duration move_duration;
    };
}


#endif // AL5D_CPP_POSECOMMAND_HPP
