#ifndef AL5D_CPP_POSETRAIT_TPP
#define	AL5D_CPP_POSETRAIT_TPP


namespace al5d
{
    template <typename BaseType>
    PoseTrait<BaseType>::PoseTrait(
        const AL5DBaseConfig& config)
        : BaseType(config)
        , poses(construct_poses(config.pose_configs))
    {
    }
    
    
    template <typename BaseType>
    JointTypeDegree PoseTrait<BaseType>::construct_poses(
        const JointNameDegree& joint_name_degree)
    {
        return JointTypeDegree(
            BaseType::get_joint_(joint_name_degree.joint_name).get_type(),
            joint_name_degree.degree);
    }
    
    
    template <typename BaseType>
    JointTypeDegrees PoseTrait<BaseType>::construct_poses(
        const JointNameDegrees& joint_name_degrees)
    {
        JointTypeDegrees joint_type_degrees;

        for (const auto& joint_name_degrees : joint_name_degrees)
        {
            joint_type_degrees.push_back(
                construct_poses(joint_name_degrees));
        }

        return joint_type_degrees;
    }
    
    
    template <typename BaseType>
    Pose PoseTrait<BaseType>::construct_poses(
        const PoseConfig& pose_config)
    {
        return Pose(
            pose_config.name,
            construct_poses(pose_config.joint_name_degrees));
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

        throw "Pose not found"; // TODO : throw class
    }


    template <typename BaseType>
    void PoseTrait<BaseType>::move_to_pose(
        const PoseName& pose_name)
    {
        const auto& pose = get_pose(pose_name);
        const auto& joint_type_degrees = pose.joint_type_degrees;
        BaseType::move_to_degrees(joint_type_degrees);
    }


    template <typename BaseType>
    void PoseTrait<BaseType>::move_to_pose(
        const PoseName& pose_name,
        const Duration &move_duration)
    {
        const auto& pose = get_pose(pose_name);
        const auto& joint_type_degrees = pose.joint_type_degrees;
        BaseType::move_to_degrees(joint_type_degrees, move_duration);
    }


    template <typename BaseType>
    void PoseTrait<BaseType>::add_poses(
        const PoseConfigs& pose_configs)
    {
        for (const auto& pose_config : pose_configs)
        {
            poses.push_back(
                construct_poses(pose_config));
        }
    }


    template <typename BaseType>
    void PoseTrait<BaseType>::set_poses(
        const PoseConfigs& pose_configs)
    {
        poses = construct_poses(pose_configs);
    }
}


#endif	/* AL5D_CPP_POSETRAIT_TPP */
