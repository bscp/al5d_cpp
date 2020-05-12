// HEADER INCLUDE
#include <al5d_cpp/traits/json_trait/json_deserialize.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    namespace // anonymous namespace, these symbols are private
    {
        Degrees load_degrees(
            const YAML::Node &json_node)
        {
            return Degrees(json_node.as<Degrees::Value>());
        }


        DegreesRange load_degrees_range(
            const YAML::Node &json_node)
        {
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
            return json_node.as<int>();
        }


        JointConfig load_joint_config(
            const YAML::Node &json_node,
            size_t joint_type)
        {
            auto degrees_range = load_degrees_range(json_node["degrees_range"]);

            return JointConfig(
                load_joint_name(json_node["name"]),
                JointType(joint_type),
                load_board_channel(json_node["board_channel"]),
                load_pulse_width_range(json_node["pulse_width_range"]),
                degrees_range);
        }


        JointConfigs load_joint_configs(
            const YAML::Node &json_node)
        {
            JointConfigs joint_configs;

            for (size_t i = 0; i < json_node.size(); ++i)
            {
                auto joint_config = load_joint_config(json_node[i], i);
                joint_configs.push_back(joint_config);
            }

            return joint_configs;
        }


        serial::BaudRate load_serial_baud_rate(
            const YAML::Node &json_node)
        {
            auto serial_baud_rate = json_node.as<int>();
            return serial::BaudRate(serial_baud_rate);
        }


        serial::Port load_serial_port(
            const YAML::Node &json_node)
        {
            auto serial_port = json_node.as<std::string>();
            return serial::Port(serial_port);
        }


        SerialConfig load_serial_config(
            const YAML::Node &json_node)
        {
            auto serial_port = load_serial_port(json_node["port"]);
            auto serial_baud_rate = load_serial_baud_rate(json_node["baud_rate"]);
            return SerialConfig(serial_port, serial_baud_rate);
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


        JointNameDegrees load_joint_name_degrees(
            const YAML::Node &json_node)
        {
            return JointNameDegrees(
                load_pose_config_joint_name(json_node["joint"]),
                load_pose_config_joint_degrees(json_node["degrees"]));
        }


        JointNameDegreesList load_pose_config_joint_degrees_list(
            const YAML::Node &json_node)
        {
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


        PoseConfig load_pose_config(
            const YAML::Node &json_node)
        {
            return PoseConfig(
                load_pose_config_name(json_node["name"]),
                load_pose_config_joint_degrees_list(json_node["joint_degrees"]));
        }


        PoseConfigs load_pose_config_configs(
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


        AL5DBaseConfig load_config(
            const YAML::Node &json_node)
        {
            return AL5DBaseConfig(
                load_joint_configs(json_node["joints"]),
                load_serial_config(json_node["serial"]),
                load_pose_config_configs(json_node["poses"]));
        }
    }


    PoseConfigs load_pose_configs_from_json_file(
        const std::string& path)
    {
        const YAML::Node config_node = YAML::LoadFile(path);
        return load_pose_config_configs(config_node);
    }


    PoseConfigs load_pose_configs_from_json(
        const std::string& json)
    {
        const YAML::Node json_node = YAML::Load(json);
        return load_pose_config_configs(json_node);
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
