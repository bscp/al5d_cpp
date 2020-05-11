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
        
        void start_timer(
            long duration);
    
        virtual void move_to(
            const JointType& joint_type,
            const Degrees &degrees,
            const Duration &move_duration
                =Duration::from_milliseconds(DURATION));

        void move_to(
            const JointTypeDegreesList &joint_type_degrees_list,
            const Duration &move_duration
                =Duration::from_milliseconds(DURATION))
            override;
    
    private:

        TimerPtr timer_ptr;
    };
}


#include "ProgressingTrait.tpp"

#endif // AL5D_CPP_PROGRESSINGTRAIT_HPP
