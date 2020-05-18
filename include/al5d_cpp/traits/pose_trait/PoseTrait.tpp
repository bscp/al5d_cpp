#ifndef AL5D_CPP_POSETRAIT_TPP
#define	AL5D_CPP_POSETRAIT_TPP

// PROJECT INCLUDES
#include <al5d_cpp/exceptions.hpp>


namespace al5d
{
    template <typename BaseType>
    PoseTrait<BaseType>::PoseTrait(
        const AL5DBaseConfig& config)
        : BaseType(config)
        , poses(construct_poses(config.posing_config.pose_configs))
        , start_pose_name(config.posing_config.start_pose_name)
        , finish_pose_name(config.posing_config.finish_pose_name)
    {
        move_to_start_pose();
    }


    template <typename BaseType>
    PoseTrait<BaseType>::~PoseTrait()
    {
        move_to_finish_pose();
    }
    
    
    template <typename BaseType>
    JointTypeAngle PoseTrait<BaseType>::construct_poses(
        const JointNameAngle& joint_name_angle)
    {
        return JointTypeAngle(
            BaseType::get_joint(joint_name_angle.joint_name).get_type(),
            joint_name_angle.angle);
    }
    
    
    template <typename BaseType>
    JointTypeAngles PoseTrait<BaseType>::construct_poses(
        const JointNameAngles& joint_name_angles)
    {
        JointTypeAngles joint_type_angles;

        for (const auto& joint_name_angle : joint_name_angles)
        {
            joint_type_angles.push_back(
                construct_poses(joint_name_angle));
        }

        return joint_type_angles;
    }
    
    
    template <typename BaseType>
    Pose PoseTrait<BaseType>::construct_poses(
        const PoseConfig& pose_config)
    {
        return Pose(
            pose_config.name,
            construct_poses(pose_config.joint_name_angles));
    }
    
    
    template <typename BaseType>
    Poses PoseTrait<BaseType>::construct_poses(
        const PoseConfigs& pose_configs)
    {
        Poses poses;

        for (const auto& pose_config : pose_configs)
        {
            poses.push_back(construct_poses(pose_config));
        }

        return poses;
    }


    template <typename BaseType>
    void PoseTrait<BaseType>::move_to_start_pose()
    {
        if (start_pose_name != "")
        {
            move_to_pose(start_pose_name);
        }
    }


    template <typename BaseType>
    void PoseTrait<BaseType>::move_to_finish_pose()
    {
        if (finish_pose_name != "")
        {
            move_to_pose(finish_pose_name);
        }
    }


    template <typename BaseType>
    const Pose& PoseTrait<BaseType>::get_pose(
        const PoseName& pose_name)
        const
    {
        for (const auto& pose : poses)
        {
            if (pose.name == pose_name)
            {
                return pose;
            }
        }

        throw InvalidPoseName(pose_name);
    }


    template <typename BaseType>
    void PoseTrait<BaseType>::move_to_pose(
        const PoseName& pose_name)
    {
        const auto& pose = get_pose(pose_name);
        const auto& joint_type_angles = pose.joint_type_angles;
        BaseType::move_to_angles(joint_type_angles);
    }


    template <typename BaseType>
    void PoseTrait<BaseType>::move_to_pose(
        const PoseName& pose_name,
        const Duration &move_duration)
    {
        const auto& pose = get_pose(pose_name);
        const auto& joint_type_angles = pose.joint_type_angles;
        BaseType::move_to_angles(joint_type_angles, move_duration);
    }


    template <typename BaseType>
    void PoseTrait<BaseType>::add_poses(
        const PosingConfig& posing_config)
    {
        for (const auto& pose_config : posing_config.pose_configs)
        {
            poses.push_back(construct_poses(pose_config));
        }
    }


    template <typename BaseType>
    void PoseTrait<BaseType>::set_poses(
        const PosingConfig& posing_config)
    {
        start_pose_name = posing_config.start_pose_name;
        finish_pose_name = posing_config.finish_pose_name;
        poses = construct_poses(posing_config.pose_configs);
        
        move_to_start_pose();
    }
}


#endif	/* AL5D_CPP_POSETRAIT_TPP */
