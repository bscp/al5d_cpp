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
    void ProgressingTrait<BaseType>::move_to_degree(
        const JointType& joint_type,
        const Degree &degree,
        const Duration &move_duration)
    {
        BaseType::move_to_degrees({{joint_type, degree}}, move_duration);
    }

    
    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to_degrees(
        const JointTypeDegrees &joint_type_degrees,
        const Duration &move_duration)
    {
        BaseType::move_to_degrees(joint_type_degrees, move_duration);
        start_timer(move_duration.in_milliseconds());
    }
}


#endif	/* AL5D_CPP_PROGRESSINGTRAIT_TPP */
