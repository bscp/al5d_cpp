#ifndef AL5D_CPP_ANGLESCOMMAND_HPP
#define AL5D_CPP_ANGLESCOMMAND_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/ContextCommand.hpp>


namespace al5d_cpp
{
    class AnglesCommand : public ContextCommand
    {
    public:

        static CommandPtr as_pointer(
            Controller* context_ptr,
            const JointNameAngles& joint_name_angles,
            const Duration& move_duration);

        explicit AnglesCommand(
            Controller* context_ptr,
            const JointNameAngles& joint_name_angles,
            const Duration& move_duration);

        void execute()
            override;

    private:

        JointNameAngles joint_name_angles;
        Duration move_duration;
    };
}


#endif // AL5D_CPP_ANGLESCOMMAND_HPP
