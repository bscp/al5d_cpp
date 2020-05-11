// HEADER INCLUDE
#include <al5d_cpp/traits/json_trait/json_deserialize.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>

// TODO : move to json_trait folder


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


        AL5DBaseConfig load_config(
            const YAML::Node &json_node)
        {
            auto joint_configs = load_joint_configs(json_node["joints"]);
            auto serial_config = load_serial_config(json_node["serial"]);
            return AL5DBaseConfig(joint_configs, serial_config);
        }
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
