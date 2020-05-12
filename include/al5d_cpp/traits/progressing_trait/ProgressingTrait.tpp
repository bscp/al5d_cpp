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
    void ProgressingTrait<BaseType>::move_to_degree(
        const JointName& joint_name,
        const Degree &degree,
        const Duration &move_duration)
    {
        BaseType::move_to_degree(joint_name, degree, move_duration);
        start_timer(move_duration);
    }
    
    
    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to_degree(
        const JointType& joint_type,
        const Degree &degree,
        const Duration &move_duration)
    {
        BaseType::move_to_degree(joint_type, degree, move_duration);
        start_timer(move_duration);
    }
    
        
    template <typename BaseType>    
    void ProgressingTrait<BaseType>::move_to_degree(
        const JointName& joint_name,
        const Degree &degree)
    {
        BaseType::move_to_degree(joint_name, degree);
    }
    
    
    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to_degree(
        const JointType& joint_type,
        const Degree &degree)
    {
        BaseType::move_to_degree(joint_type, degree);
    }
    
        
    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to_degrees(
        const JointNameDegrees &joint_name_degrees,
        const Duration &move_duration)
    {
        BaseType::move_to_degrees(joint_name_degrees, move_duration);
        start_timer(move_duration);
    }
    
    
    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to_degrees(
        const JointTypeDegrees &joint_type_degrees,
        const Duration &move_duration)
    {
        BaseType::move_to_degrees(joint_type_degrees, move_duration);
        start_timer(move_duration);
    }
    

    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to_degrees(
        const JointNameDegrees &joint_name_degrees)
    {
        BaseType::move_to_degrees(joint_name_degrees);
    }

    
    template <typename BaseType>
    void ProgressingTrait<BaseType>::move_to_degrees(
        const JointTypeDegrees &joint_type_degrees)
    {
        BaseType::move_to_degrees(joint_type_degrees);
    }
}


#endif	/* AL5D_CPP_PROGRESSINGTRAIT_TPP */
