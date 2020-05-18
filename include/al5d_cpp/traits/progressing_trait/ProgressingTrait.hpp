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

        virtual ~ProgressingTrait();

        bool is_moving()
            const;
        
        virtual void move_to_angles(
            const JointNameAngles &joint_name_angles,
            const Duration &move_duration)
            override;
    
        virtual void move_to_angles(
            const JointTypeAngles &joint_type_angles,
            const Duration &move_duration)
            override;
        
        virtual void move_to_angles(
            const JointNameAngles &joint_name_angles)
            override;
    
        virtual void move_to_angles(
            const JointTypeAngles &joint_type_angles)
            override;
    
    private:
        
        void start_timer(
            const Duration &move_duration);

        TimerPtr timer_ptr;
    };
}


#include "ProgressingTrait.tpp"

#endif // AL5D_CPP_PROGRESSINGTRAIT_HPP
