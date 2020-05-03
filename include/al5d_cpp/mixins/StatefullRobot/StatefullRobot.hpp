#ifndef AL5D_CPP_STATEFULLROBOT_HPP
#define AL5D_CPP_STATEFULLROBOT_HPP

// PROJECT INCLUDES
#include <al5d_cpp/Timer.hpp>

#define DURATION 3000 // in milliseconds


namespace al5d
{
    template <typename BaseType>
    class StatefullRobot : public BaseType
    {
    public:
        typedef typename BaseType::Config Config;

        explicit StatefullRobot(
            const Config& config);

        virtual ~StatefullRobot() = default;

        bool is_moving()
            const;
        
        void start_timer(
            long duration);
                
        void move_to(
            const JointTypeAngles &joint_type_angles)
            override;

        void move_to(
            const JointTypeAngle &joint_type_angle)
            override;

        void move_to(
            const JointTypeAngles &joint_type_angles,
            const Duration &move_duration)
            override;

        void move_to(
            const JointTypeAngle &joint_type_angle,
            const Duration &move_duration)
            override;
    
    private:

        TimerPtr timer_ptr;
    };
}


#include "StatefullRobot.tpp"

#endif // AL5D_CPP_STATEFULLROBOT_HPP
