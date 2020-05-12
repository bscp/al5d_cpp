#ifndef AL5D_CPP_POSETRAIT_HPP
#define AL5D_CPP_POSETRAIT_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>
#include <al5d_cpp/traits/pose_trait/Pose.hpp>
#include <al5d_cpp/base/configs/PoseConfig.hpp>
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

        virtual ~PoseTrait() = default;

        void move_to_pose(
            const PoseName& pose_name);

        void move_to_pose(
            const PoseName& pose_name,
            const Duration &move_duration);

    private:

        JointType construct_poses(
            const JointName& joint_name);

        JointTypeDegrees construct_poses(
            const JointNameDegrees& joint_name_degrees);

        JointTypeDegreesList construct_poses(
            const JointNameDegreesList& joint_name_degrees_list);
            
        Pose construct_poses(
            const PoseConfig& pose_config);

        void construct_poses(
            const PoseConfigs& pose_configs);

        const Pose& get_pose(
            const PoseName& pose_name)
            const;

        Poses poses;
    };
}


#include "PoseTrait.tpp"

#endif // AL5D_CPP_POSETRAIT_HPP
