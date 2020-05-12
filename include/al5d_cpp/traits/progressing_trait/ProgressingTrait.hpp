#ifndef AL5D_CPP_PROGRESSINGTRAIT_HPP
#define AL5D_CPP_PROGRESSINGTRAIT_HPP

// PROJECT INCLUDES
#include <al5d_cpp/Timer.hpp>
#include <al5d_cpp/base/settings.hpp>
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>


namespace al5d
{
    template <typename BaseType>
    class ProgressingTrait : public BaseType
    {
    public:

        explicit ProgressingTrait(
            const AL5DBaseConfig& config);

        virtual ~ProgressingTrait() = default;

        bool is_moving()
            const;
    
        virtual void move_to_degree(
            const JointName& joint_name,
            const Degree &degree,
            const Duration &move_duration)
            override;
    
        virtual void move_to_degree(
            const JointType& joint_type,
            const Degree &degree,
            const Duration &move_duration)
            override;
            
        virtual void move_to_degree(
            const JointName& joint_name,
            const Degree &degree)
            override;
    
        virtual void move_to_degree(
            const JointType& joint_type,
            const Degree &degree)
            override;
        
        virtual void move_to_degrees(
            const JointNameDegrees &joint_name_degrees,
            const Duration &move_duration)
            override;
    
        virtual void move_to_degrees(
            const JointTypeDegrees &joint_type_degrees,
            const Duration &move_duration)
            override;
        
        virtual void move_to_degrees(
            const JointNameDegrees &joint_name_degrees)
            override;
    
        virtual void move_to_degrees(
            const JointTypeDegrees &joint_type_degrees)
            override;
    
    private:
        
        void start_timer(
            const Duration &move_duration);

        TimerPtr timer_ptr;
    };
}


#include "ProgressingTrait.tpp"

#endif // AL5D_CPP_PROGRESSINGTRAIT_HPP
