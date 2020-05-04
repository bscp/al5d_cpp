#ifndef AL5D_CPP_PROGRESSINGTRAIT_TPP
#define	AL5D_CPP_PROGRESSINGTRAIT_TPP


namespace al5d
{
    template <typename BaseType>
    ProgressingTrait<BaseType>::ProgressingTrait(
        const Config& config)
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
        const JointTypeAngles &joint_type_angles)
    {
        BaseType::move_to(joint_type_angles);
        start_timer(DURATION);
    }
    
    
    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to(
        const JointTypeAngle &joint_type_angle)
    {
        BaseType::move_to(joint_type_angle);
        start_timer(DURATION);
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
        BaseType::move_to(joint_type_angle, move_duration);
        start_timer(move_duration.in_milliseconds());
    }
}


#endif	/* AL5D_CPP_PROGRESSINGTRAIT_TPP */
