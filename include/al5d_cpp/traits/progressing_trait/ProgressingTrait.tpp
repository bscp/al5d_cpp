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
    ProgressingTrait<BaseType>::~ProgressingTrait()
    {
    }
    
    
    template <typename BaseType>
    void ProgressingTrait<BaseType>::start_timer(
        const Duration &move_duration)
    {
        timer_ptr = Timer::as_pointer(move_duration.in_milliseconds());
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
    void ProgressingTrait<BaseType>::move_to_angles(
        const JointNameAngles &joint_name_angles,
        const Duration &move_duration)
    {
        BaseType::move_to_angles(joint_name_angles, move_duration);
        start_timer(move_duration);
    }
    
    
    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to_angles(
        const JointTypeAngles &joint_type_angles,
        const Duration &move_duration)
    {
        BaseType::move_to_angles(joint_type_angles, move_duration);
        start_timer(move_duration);
    }
    

    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to_angles(
        const JointNameAngles &joint_name_angles)
    {
        BaseType::move_to_angles(joint_name_angles);
    }

    
    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to_angles(
        const JointTypeAngles &joint_type_angles)
    {
        BaseType::move_to_angles(joint_type_angles);
    }
}


#endif	/* AL5D_CPP_PROGRESSINGTRAIT_TPP */
