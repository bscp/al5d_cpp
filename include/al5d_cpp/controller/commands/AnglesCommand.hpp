#ifndef AL5D_CPP_ANGLESCOMMAND_HPP
#define AL5D_CPP_ANGLESCOMMAND_HPP

// PROJECT INCLUDES
#include <al5d_cpp/controller/ContextCommand.hpp>
#include <al5d_cpp/settings.hpp>


namespace al5d
{
    class AnglesCommand : public ContextCommand
    {
    public:

        static CommandPtr as_ptr(
            Controller* context_ptr,
            const JointTypeAngles& joint_type_angles,
            const Duration& move_duration);

        static CommandPtr as_ptr(
            Controller* context_ptr,
            const JointTypeAngles& joint_type_angles);

        explicit AnglesCommand(
            Controller* context_ptr,
            const JointTypeAngles& joint_type_angles,
            const Duration& move_duration=
                Duration::from_milliseconds(MILLISECONDS));

        virtual ~AnglesCommand() = default;

        void execute()
            override;

    private:

        JointTypeAngles joint_type_angles;
        Duration move_duration;
    };
}


#endif // AL5D_CPP_ANGLESCOMMAND_HPP
