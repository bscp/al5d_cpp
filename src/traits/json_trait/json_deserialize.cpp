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
                throw std::runtime_error("'" + key + "' does not exist in config");
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


        Degrees load_degrees(
            const YAML::Node &json_node)
        {
            return Degrees(json_node.as<Degrees::Value>());
        }


        DegreesRange load_degrees_range(
            const YAML::Node &json_node)
        {
            validate_size(json_node, /*size*/2);
            return DegreesRange(
                load_degrees(json_node[0]),
                load_degrees(json_node[1]));
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
        #define JOINT_DEGREES_RANGE_KEY "degrees_range"
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
                load_degrees_range(json_node[JOINT_DEGREES_RANGE_KEY]));
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


        #define SERIAL_PORT_KEY "port"
        #define SERIAL_BAUD_RATE_KEY "baud_rate"
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


        Degrees load_pose_config_joint_degrees(
            const YAML::Node &json_node)
        {
            return Degrees(json_node.as<Degrees::Value>());
        }


        #define POSE_CONFIG_JOINT_NAME_KEY "joint"
        #define POSE_CONFIG_JOINT_DEGREES_KEY "degrees"
        JointNameDegrees load_joint_name_degrees(
            const YAML::Node &json_node)
        {
            validate_key(json_node, POSE_CONFIG_JOINT_NAME_KEY);
            validate_key(json_node, POSE_CONFIG_JOINT_DEGREES_KEY);

            return JointNameDegrees(
                load_pose_config_joint_name(
                    json_node[POSE_CONFIG_JOINT_NAME_KEY]),
                load_pose_config_joint_degrees(
                    json_node[POSE_CONFIG_JOINT_DEGREES_KEY]));
        }


        JointNameDegreesList load_pose_config_joint_degrees_list(
            const YAML::Node &json_node)
        {
            validate_min_size(json_node, /*size*/1);
            JointNameDegreesList joint_name_degrees_list;

            for (size_t i = 0; i < json_node.size(); ++i)
            {
                joint_name_degrees_list.push_back(
                    load_joint_name_degrees(json_node[i]));
            }

            return joint_name_degrees_list;
        }


        PoseName load_pose_config_name(
            const YAML::Node &json_node)
        {
            return json_node.as<PoseName>();
        }


        #define POSE_CONFIG_NAME "name"
        #define POSE_CONFIG_JOINT_NAME_DEGREES_KEY "joint_degrees"
        PoseConfig load_pose_config(
            const YAML::Node &json_node)
        {
            validate_key(json_node, POSE_CONFIG_NAME);
            validate_key(json_node, POSE_CONFIG_JOINT_NAME_DEGREES_KEY);

            return PoseConfig(
                load_pose_config_name(
                    json_node[POSE_CONFIG_NAME]),
                load_pose_config_joint_degrees_list(
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


        #define JOINT_CONFIGS_KEY "joints"
        #define SERIAL_CONFIG_KEY "serial"
        #define POSE_CONFIGS_KEY "poses"
        AL5DBaseConfig load_config(
            const YAML::Node &json_node)
        {
            validate_key(json_node, JOINT_CONFIGS_KEY);
            validate_key(json_node, SERIAL_CONFIG_KEY);
            validate_key(json_node, POSE_CONFIGS_KEY);

            return AL5DBaseConfig(
                load_joint_configs(json_node[JOINT_CONFIGS_KEY]),
                load_serial_config(json_node[SERIAL_CONFIG_KEY]),
                load_pose_configs(json_node[POSE_CONFIGS_KEY]));
        }
    }


    PoseConfigs load_pose_configs_from_json_file(
        const std::string& path)
    {
        const YAML::Node config_node = YAML::LoadFile(path);
        return load_pose_configs(config_node);
    }


    PoseConfigs load_pose_configs_from_json(
        const std::string& json)
    {
        const YAML::Node json_node = YAML::Load(json);
        return load_pose_configs(json_node);
    }


    AL5DBaseConfig load_config_from_json_file(
        const std::string& path)
    {
        const YAML::Node config_node = YAML::LoadFile(path);
        return load_config(config_node);
    }


    AL5DBaseConfig load_config_from_json(
        const std::string& json)
    {
        const YAML::Node json_node = YAML::Load(json);
        return load_config(json_node);
    }
}
