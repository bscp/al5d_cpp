// HEADER INCLUDE
#include <al5d_cpp/base/AL5DBase.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/exceptions.hpp>
#include <al5d_cpp/settings.hpp>


namespace al5d
{   
    
    JointTypeAngle AL5DBase::construct_poses(
        const JointNameAngle& joint_name_angle)
        const
    {
        return JointTypeAngle(
            get_joint(joint_name_angle.joint_name).get_type(),
            joint_name_angle.angle);
    }
    
    
    JointTypeAngles AL5DBase::construct_poses(
        const JointNameAngles& joint_name_angles)
        const
    {
        JointTypeAngles joint_type_angles;

        for (const auto& joint_name_angle : joint_name_angles)
        {
            joint_type_angles.push_back(
                construct_poses(joint_name_angle));
        }

        return joint_type_angles;
    }
    
    
    Pose AL5DBase::construct_poses(
        const PoseConfig& pose_config)
        const
    {
        return Pose(
            pose_config.name,
            construct_poses(pose_config.joint_name_angles));
    }
    
    
    Poses AL5DBase::construct_poses(
        const PoseConfigs& pose_configs)
        const
    {
        Poses poses;

        for (const auto& pose_config : pose_configs)
        {
            poses.push_back(construct_poses(pose_config));
        }

        return poses;
    }


    void AL5DBase::move_to_start_pose()
    {
        if (start_pose_name != "")
        {
            move_to_pose(
                start_pose_name,
                Duration::from_milliseconds(INITIALIZE_MOVE_DURATION));
        }
    }


    void AL5DBase::move_to_finish_pose()
    {
        if (finish_pose_name != "")
        {
            move_to_pose(
                finish_pose_name,
                Duration::from_milliseconds(FINALIZE_MOVE_DURATION));
        }
    }


    const Pose& AL5DBase::get_pose(
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


    void AL5DBase::move_to_pose(
        const PoseName& pose_name)
    {
        const auto& pose = get_pose(pose_name);
        const auto& joint_type_angles = pose.joint_type_angles;
        move_to_angles(joint_type_angles);
    }


    void AL5DBase::move_to_pose(
        const PoseName& pose_name,
        const Duration &move_duration)
    {
        const auto& pose = get_pose(pose_name);
        const auto& joint_type_angles = pose.joint_type_angles;
        move_to_angles(joint_type_angles, move_duration);
    }


    void AL5DBase::add_poses(
        const PosingConfig& posing_config)
    {
        for (const auto& pose_config : posing_config.pose_configs)
        {
            poses.push_back(construct_poses(pose_config));
        }
    }


    void AL5DBase::set_poses(
        const PosingConfig& posing_config)
    {
        start_pose_name = posing_config.start_pose_name;
        finish_pose_name = posing_config.finish_pose_name;
        poses = construct_poses(posing_config.pose_configs);
        
        move_to_start_pose();
    }
}
