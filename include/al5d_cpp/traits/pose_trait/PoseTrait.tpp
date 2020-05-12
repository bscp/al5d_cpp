#ifndef AL5D_CPP_POSETRAIT_TPP
#define	AL5D_CPP_POSETRAIT_TPP


namespace al5d
{
    template <typename BaseType>
    PoseTrait<BaseType>::PoseTrait(
        const AL5DBaseConfig& config)
        : BaseType(config)
        , poses()
    {
        construct_poses(config.pose_configs);
    }
    
    
    template <typename BaseType>
    JointTypeDegrees PoseTrait<BaseType>::construct_poses(
        const JointNameDegrees& joint_name_degrees)
    {
        return JointTypeDegrees(
            BaseType::get_joint(joint_name_degrees.joint_name).get_type(),
            joint_name_degrees.degrees);
    }
    
    
    template <typename BaseType>
    JointTypeDegreesList PoseTrait<BaseType>::construct_poses(
        const JointNameDegreesList& joint_name_degrees_list)
    {
        JointTypeDegreesList joint_type_degrees_list;

        for (const auto& joint_name_degrees : joint_name_degrees_list)
        {
            joint_type_degrees_list.push_back(
                construct_poses(joint_name_degrees));
        }

        return joint_type_degrees_list;
    }
    
    
    template <typename BaseType>
    Pose PoseTrait<BaseType>::construct_poses(
        const PoseConfig& pose_config)
    {
        return Pose(
            pose_config.name,
            construct_poses(pose_config.joint_name_degrees_list));
    }
    
    
    template <typename BaseType>
    void PoseTrait<BaseType>::construct_poses(
        const PoseConfigs& pose_configs)
    {
        for (const auto& pose_config : pose_configs)
        {
            poses.push_back(construct_poses(pose_config));
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

        throw "Pose not found"; // TODO : throw class
    }


    template <typename BaseType>
    void PoseTrait<BaseType>::move_to_pose(
        const PoseName& pose_name)
    {
        const auto& pose = get_pose(pose_name);
        const auto& joint_type_degrees_list = pose.joint_type_degrees_list;
        BaseType::move_to(joint_type_degrees_list);
    }


    template <typename BaseType>
    void PoseTrait<BaseType>::move_to_pose(
        const PoseName& pose_name,
        const Duration &move_duration)
    {
        const auto& pose = get_pose(pose_name);
        const auto& joint_type_degrees_list = pose.joint_type_degrees_list;
        BaseType::move_to(joint_type_degrees_list, move_duration);
    }
}


#endif	/* AL5D_CPP_POSETRAIT_TPP */
