#ifndef AL5D_CPP_LOGGINGTRAIT_TPP
#define	AL5D_CPP_LOGGINGTRAIT_TPP

// PROJECT INCLUDES
#include <al5d_cpp/AL5D_logging.hpp>


namespace al5d
{
    template <typename BaseType>
    LoggingTrait<BaseType>::LoggingTrait(
        const AL5DBaseConfig& config)
        : BaseType(config)
    {
    }
    // template <typename BaseType> // TODO : fix todo in header file
    // void LoggingTrait<BaseType>::move_to_degree(
    //     const JointTypeDegreesList &joint_type_degrees_list,
    //     const Duration &move_duration)
    // {
    //     log_moving_joints(joint_type_degrees_list, move_duration);
    //     BaseType::move_to(joint_type_degrees_list, move_duration);
    // }
    
    
    template <typename BaseType>
    void LoggingTrait<BaseType>::do_emergency_stop()
    {
        log_emergency_stop();
        BaseType::do_emergency_stop();
    }

    
    template <typename BaseType>
    void LoggingTrait<BaseType>::transmit_command(
        const Command &command)
    {
        log_transmit_command(command);
        BaseType::transmit_command(command);
    }
}


#endif	/* AL5D_CPP_LOGGINGTRAIT_TPP */
