#ifndef AL5D_CPP_PROGRESSINGTRAIT_HPP
#define AL5D_CPP_PROGRESSINGTRAIT_HPP

// PROJECT INCLUDES
#include <al5d_cpp/Timer.hpp>
#include <al5d_cpp/base/settings.hpp>


namespace al5d
{
    template <typename BaseType>
    class ProgressingTrait : public BaseType
    {
    public:
        typedef typename BaseType::Config Config;

        explicit ProgressingTrait(
            const Config& config);

        virtual ~ProgressingTrait() = default;

        bool is_moving()
            const;
        
        void start_timer(
            long duration);

        void move_to(
            const JointTypeAngles &joint_type_angles,
            const Duration &move_duration
                =Duration::from_milliseconds(DURATION))
            override;

        void move_to( // TODO : why can this be removed?
            const JointTypeAngle &joint_type_angle,
            const Duration &move_duration
                =Duration::from_milliseconds(DURATION))
            override;
    
    private:

        TimerPtr timer_ptr;
    };
}


#include "ProgressingTrait.tpp"

#endif // AL5D_CPP_PROGRESSINGTRAIT_HPP
