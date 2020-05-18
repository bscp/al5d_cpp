#ifndef AL5D_CPP_POSETRAIT_HPP
#define AL5D_CPP_POSETRAIT_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>
#include <al5d_cpp/traits/pose_trait/Pose.hpp>
#include <al5d_cpp/base/configs/PosingConfig.hpp>
#include <al5d_cpp/base/types.hpp>
#include <al5d_cpp/Duration.hpp>


namespace al5d
{
    template <typename BaseType>
    class PoseTrait : public BaseType
    {
    public:

        explicit PoseTrait(
            const AL5DBaseConfig& config);

        virtual ~PoseTrait();

        void move_to_pose(
            const PoseName& pose_name);

        void move_to_pose(
            const PoseName& pose_name,
            const Duration &move_duration);

        void add_poses(
            const PosingConfig& posing_config);

        void set_poses(
            const PosingConfig& posing_config);

    private:

        JointType construct_poses(
            const JointName& joint_name);

        JointTypeAngle construct_poses(
            const JointNameAngle& joint_name_angle);

        JointTypeAngles construct_poses(
            const JointNameAngles& joint_name_angles);
            
        Pose construct_poses(
            const PoseConfig& pose_config);

        Poses construct_poses(
            const PoseConfigs& pose_configs);

        void move_to_start_pose();
        
        void move_to_finish_pose();

        const Pose& get_pose(
            const PoseName& pose_name)
            const;

        Poses poses;
        PoseName start_pose_name;
        PoseName finish_pose_name;
    };
}


#include "PoseTrait.tpp"

#endif // AL5D_CPP_POSETRAIT_HPP
