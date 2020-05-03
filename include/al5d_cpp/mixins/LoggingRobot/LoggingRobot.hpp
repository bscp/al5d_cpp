#ifndef AL5D_CPP_LOGGINGROBOT_HPP
#define AL5D_CPP_LOGGINGROBOT_HPP


namespace al5d
{
    template <typename BaseType>
    class LoggingRobot : public BaseType
    {
    public:
        typedef typename BaseType::Config Config;

        explicit LoggingRobot(
            const Config& config);

        virtual ~LoggingRobot() = default;

        void move_to(
            const JointTypeAngles &joint_type_angles)
            override;

        void move_to(
            const JointTypeAngle &joint_type_angle)
            override;

        void move_to(
            const JointTypeAngles &joint_type_angles,
            const Duration &move_duration)
            override;

        void move_to(
            const JointTypeAngle &joint_type_angle,
            const Duration &move_duration)
            override;

        void do_emergency_stop()
            override;

        void transmit_command(
            const Command &command)
            override;
    };
}


#include "LoggingRobot.tpp"

#endif // AL5D_CPP_LOGGINGROBOT_HPP
