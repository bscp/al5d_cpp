#ifndef AL5D_CPP_PROGRESSINGTRAIT_TPP
#define	AL5D_CPP_PROGRESSINGTRAIT_TPP


namespace al5d
{
    template <typename BaseType>
    ProgressingTrait<BaseType>::ProgressingTrait(
        const AL5DBaseConfig& config)
        : BaseType(config)
    {
    }
    
    
    template <typename BaseType>
    void ProgressingTrait<BaseType>::start_timer(
        long duration)
    {
        timer_ptr = Timer::as_pointer(duration);
    }
    
    
    template <typename BaseType>
    bool ProgressingTrait<BaseType>::is_moving()
        const
    {
        if (timer_ptr == nullptr)
        {
            return false;
        }
        
        return !timer_ptr->has_elapsed();
    }
    
    
    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to(
        const JointTypeAngles &joint_type_angles,
        const Duration &move_duration)
    {
        BaseType::move_to(joint_type_angles, move_duration);
        start_timer(move_duration.in_milliseconds());
    }
    
    
    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to(
        const JointTypeAngle &joint_type_angle,
        const Duration &move_duration)
    {
        move_to({joint_type_angle}, move_duration);
    }
}


#endif	/* AL5D_CPP_PROGRESSINGTRAIT_TPP */
