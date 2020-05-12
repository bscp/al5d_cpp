#ifndef AL5D_CPP_LOGGINGTRAIT_HPP
#define AL5D_CPP_LOGGINGTRAIT_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>


namespace al5d
{
    template <typename BaseType>
    class LoggingTrait : public BaseType
    {
    public:
        typedef typename BaseType::Config Config;

        explicit LoggingTrait(
            const AL5DBaseConfig& config);

        virtual ~LoggingTrait() = default;

        // void move_to_degree( // TODO : implement all overloading methods, because its needed...
        //     const JointTypeDegreeList &joint_type_degree_list,
        //     const Duration &move_duration)
        //     override;

        void do_emergency_stop()
            override;

        void transmit_command(
            const Command &command)
            override;
    };
}


#include "LoggingTrait.tpp"

#endif // AL5D_CPP_LOGGINGTRAIT_HPP
