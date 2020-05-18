// HEADER INCLUDE
#include <al5d_cpp/traits/json_trait/json_deserialize.hpp>

// SYSTEM INCLUDES
#include <exception>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    namespace // anonymous namespace, these symbols are private
    {
        void validate_key(
            const YAML::Node &json_node,
            const std::string& key)
        {
            if (!json_node[key])
            {
                throw std::runtime_error(std::string("'") + key + "' does not exist in config");
            }
        }


        void validate_size(
            const YAML::Node &json_node,
            size_t size)
        {
            if (json_node.size() != size)
            { // TODO : throw exception class
                throw std::runtime_error("List does not have the right size");
            }
        }


        void validate_min_size(
            const YAML::Node &json_node,
            size_t size)
        {
            if (json_node.size() < size)
            { // TODO : throw exception class
                throw std::runtime_error("List does not have the right size");
            }
        }


        Degree load_degree(
            const YAML::Node &json_node)
        {
            return Degree(json_node.as<Degree::Value>());
        }


        DegreeRange load_degree_range(
            const YAML::Node &json_node)
        {
            validate_size(json_node, /*size*/2);
            return DegreeRange(
                load_degree(json_node[0]),
                load_degree(json_node[1]));
        }


        PulseWidth load_pulse_width(
            const YAML::Node &json_node)
        {
            return PulseWidth(json_node.as<PulseWidth::Value>());
        }


        PulseWidthRange load_pulse_width_range(
            const YAML::Node &json_node)
        {
            validate_size(json_node, /*size*/2);
            return PulseWidthRange(
                load_pulse_width(json_node[0]),
                load_pulse_width(json_node[1]));
        }


        JointName load_joint_name(
            const YAML::Node &json_node)
        {
            return json_node.as<JointName>();
        }


        BoardChannel load_board_channel(
            const YAML::Node &json_node)
        {
            return json_node.as<BoardChannel>();
        }


        #define JOINT_NAME_KEY "name"
        #define JOINT_BOARD_CHANNEL_KEY "board_channel"
        #define JOINT_PULSE_WIDTH_RANGE_KEY "pulse_width_range"
        #define JOINT_DEGREES_RANGE_KEY "degree_range"
        JointConfig load_joint_config(
            const YAML::Node &json_node,
            size_t joint_type)
        {
            validate_key(json_node, JOINT_NAME_KEY);
            validate_key(json_node, JOINT_BOARD_CHANNEL_KEY);
            validate_key(json_node, JOINT_PULSE_WIDTH_RANGE_KEY);
            validate_key(json_node, JOINT_DEGREES_RANGE_KEY);

            return JointConfig(
                load_joint_name(json_node[JOINT_NAME_KEY]),
                JointType(joint_type),
                load_board_channel(json_node[JOINT_BOARD_CHANNEL_KEY]),
                load_pulse_width_range(json_node[JOINT_PULSE_WIDTH_RANGE_KEY]),
                load_degree_range(json_node[JOINT_DEGREES_RANGE_KEY]));
        }


        JointConfigs load_joint_configs(
            const YAML::Node &json_node)
        {
            validate_size(json_node, /*size*/6);
            JointConfigs joint_configs;

            for (size_t i = 0; i < json_node.size(); ++i)
            {
                joint_configs.push_back(
                    load_joint_config(json_node[i], i));
            }

            return joint_configs;
        }


        serial::BaudRate load_serial_baud_rate(
            const YAML::Node &json_node)
        {
            return serial::BaudRate(json_node.as<int>());
        }


        serial::Port load_serial_port(
            const YAML::Node &json_node)
        {
            return serial::Port(json_node.as<std::string>());
        }


        #define SERIAL_PORT_KEY "serial_port"
        #define SERIAL_BAUD_RATE_KEY "serial_baud_rate"
        SerialConfig load_serial_config(
            const YAML::Node &json_node)
        {
            validate_key(json_node, SERIAL_PORT_KEY);
            validate_key(json_node, SERIAL_BAUD_RATE_KEY);

            return SerialConfig(
                load_serial_port(json_node[SERIAL_PORT_KEY]),
                load_serial_baud_rate(json_node[SERIAL_BAUD_RATE_KEY]));
        }


        PoseName load_pose_config_joint_name(
            const YAML::Node &json_node)
        {
            return json_node.as<JointName>();
        }


        Angle load_pose_config_joint_angle(
            const YAML::Node &json_node)
        {
            const auto degree = json_node.as<Degree::Value>();
            return Angle::from_degree(degree);
        }


        #define POSE_CONFIG_JOINT_NAME_KEY "joint"
        #define POSE_CONFIG_JOINT_DEGREES_KEY "degree"
        JointNameAngle load_joint_name_angle(
            const YAML::Node &json_node)
        {
            validate_key(json_node, POSE_CONFIG_JOINT_NAME_KEY);
            validate_key(json_node, POSE_CONFIG_JOINT_DEGREES_KEY);

            return JointNameAngle(
                load_pose_config_joint_name(
                    json_node[POSE_CONFIG_JOINT_NAME_KEY]),
                load_pose_config_joint_angle(
                    json_node[POSE_CONFIG_JOINT_DEGREES_KEY]));
        }


        JointNameAngles load_pose_config_joint_name_angles(
            const YAML::Node &json_node)
        {
            validate_min_size(json_node, /*size*/1);
            JointNameAngles joint_name_angles;

            for (size_t i = 0; i < json_node.size(); ++i)
            {
                joint_name_angles.push_back(
                    load_joint_name_angle(json_node[i]));
            }

            return joint_name_angles;
        }


        PoseName load_pose_name(
            const YAML::Node &json_node)
        {
            return json_node.as<PoseName>();
        }


        #define POSE_CONFIG_NAME "name"
        #define POSE_CONFIG_JOINT_NAME_DEGREES_KEY "joint_degree"
        PoseConfig load_pose_config(
            const YAML::Node &json_node)
        {
            validate_key(json_node, POSE_CONFIG_NAME);
            validate_key(json_node, POSE_CONFIG_JOINT_NAME_DEGREES_KEY);

            return PoseConfig(
                load_pose_name(
                    json_node[POSE_CONFIG_NAME]),
                load_pose_config_joint_name_angles(
                    json_node[POSE_CONFIG_JOINT_NAME_DEGREES_KEY]));
        }


        PoseConfigs load_pose_configs(
            const YAML::Node &json_node)
        {
            PoseConfigs pose_configs;

            for (size_t i = 0; i < json_node.size(); ++i)
            {
                pose_configs.push_back(
                    load_pose_config(json_node[i]));
            }

            return pose_configs;
        }


        #define POSES_CONFIG_KEY "poses"
        #define START_POSE_NAME_KEY "start_pose_name"
        #define FINISH_POSE_NAME_KEY "finish_pose_name"
        PosingConfig load_posing_config(
            const YAML::Node &json_node)
        {
            validate_key(json_node, POSES_CONFIG_KEY);
            validate_key(json_node, START_POSE_NAME_KEY);
            validate_key(json_node, FINISH_POSE_NAME_KEY);

            return PosingConfig(
                load_pose_configs(json_node[POSES_CONFIG_KEY]),
                load_pose_name(json_node[START_POSE_NAME_KEY]), // TODO : make optional
                load_pose_name(json_node[FINISH_POSE_NAME_KEY])); // TODO : make optional
        }


        #define JOINT_CONFIGS_KEY "joints"
        #define COMMUNICATOR_CONFIG_KEY "communicator"
        #define POSING_CONFIG_KEY "posing"
        AL5DBaseConfig load_config(
            const YAML::Node &json_node)
        {
            validate_key(json_node, JOINT_CONFIGS_KEY);
            validate_key(json_node, COMMUNICATOR_CONFIG_KEY);
            validate_key(json_node, POSING_CONFIG_KEY);

            return AL5DBaseConfig(
                load_joint_configs(json_node[JOINT_CONFIGS_KEY]),
                load_serial_config(json_node[COMMUNICATOR_CONFIG_KEY]),
                load_posing_config(json_node[POSING_CONFIG_KEY])); // TODO : make optional
        }
    }


    PosingConfig load_posing_config_from_json_file(
        const std::string& path)
    {
        return load_posing_config(YAML::LoadFile(path));
    }


    PosingConfig load_posing_config_from_json(
        const std::string& json)
    {
        return load_posing_config(YAML::Load(json));
    }


    AL5DBaseConfig load_config_from_json_file(
        const std::string& path)
    {
        auto config = load_config(YAML::LoadFile(path));
        return config;
    }


    AL5DBaseConfig load_config_from_json(
        const std::string& json)
    {
        return load_config(YAML::Load(json));
    }
}
