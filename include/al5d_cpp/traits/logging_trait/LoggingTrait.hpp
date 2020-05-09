#ifndef AL5D_CPP_LOGGINGTRAIT_HPP
#define AL5D_CPP_LOGGINGTRAIT_HPP


namespace al5d
{
    template <typename BaseType>
    class LoggingTrait : public BaseType
    {
    public:
        typedef typename BaseType::Config Config;

        explicit LoggingTrait(
            const Config& config);

        virtual ~LoggingTrait() = default;

        void move_to(
            const JointTypeAngles &joint_type_angles,
            const Duration &move_duration)
            override;

        void do_emergency_stop()
            override;

        void transmit_command(
            const Command &command)
            override;

        // TODO : add void enable_logging()
        // TODO : add void disable_logging()
        // TODO : add set_log_level()
    };
}


#include "LoggingTrait.tpp"

#endif // AL5D_CPP_LOGGINGTRAIT_HPP
