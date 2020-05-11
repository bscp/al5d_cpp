// HEADER INCLUDE
#include <al5d_cpp/traits/json_trait/json_deserialize.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    namespace // anonymous namespace, these symbols are private
    {
        std::vector<Degrees> load_degrees_range(
            const YAML::Node &degrees_node)
        {
            std::vector<Degrees> degrees_range;
            degrees_range.push_back(degrees_node[0].as<int>());
            degrees_range.push_back(degrees_node[1].as<int>());
            return degrees_range;
        }


        PulseWidth load_pulse_width(
            const YAML::Node &pulse_width_node)
        {
            auto pulse_width_value = pulse_width_node.as<PulseWidth::Value>();
            return PulseWidth(pulse_width_value);
        }


        PulseWidthRange load_pulse_width_range(
            const YAML::Node &pulse_width_range_node)
        {
            return PulseWidthRange(
                load_pulse_width(pulse_width_range_node[0]),
                load_pulse_width(pulse_width_range_node[1]));
        }


        JointName load_joint_name(
            const YAML::Node &joint_name_node)
        {
            return joint_name_node.as<JointName>();
        }


        BoardChannel load_board_channel(
            const YAML::Node &channel_node)
        {
            return channel_node.as<int>();
        }


        JointConfig load_joint_config(
            const YAML::Node &joint_config_node,
            size_t joint_type)
        {
            auto pulse_width_range = load_pulse_width_range(joint_config_node["pulse_width_range"]);
            auto degrees_range = load_degrees_range(joint_config_node["degrees_range"]);

            return JointConfig(
                load_joint_name(joint_config_node["name"]),
                JointType(joint_type),
                load_board_channel(joint_config_node["board_channel"]),
                pulse_width_range,
                degrees_range[0],
                degrees_range[1]);
        }


        JointConfigs load_joint_configs(
            const YAML::Node &joint_configs_node)
        {
            JointConfigs joint_configs;

            for (size_t i = 0; i < joint_configs_node.size(); ++i)
            {
                auto joint_config = load_joint_config(joint_configs_node[i], i);
                joint_configs.push_back(joint_config);
            }

            return joint_configs;
        }


        serial::BaudRate load_serial_baud_rate(
            const YAML::Node &serial_port_node)
        {
            auto serial_baud_rate = serial_port_node.as<int>();
            return serial::BaudRate(serial_baud_rate);
        }


        serial::Port load_serial_port(
            const YAML::Node &serial_port_node)
        {
            auto serial_port = serial_port_node.as<std::string>();
            return serial::Port(serial_port);
        }


        SerialConfig load_serial_config(
            const YAML::Node &serial_config_node)
        {
            auto serial_port = load_serial_port(serial_config_node["port"]);
            auto serial_baud_rate = load_serial_baud_rate(serial_config_node["baud_rate"]);
            return SerialConfig(serial_port, serial_baud_rate);
        }


        AL5DBaseConfig load_config(
            const YAML::Node &config_node)
        {
            auto joint_configs = load_joint_configs(config_node["joints"]);
            auto serial_config = load_serial_config(config_node["serial"]);
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
        const YAML::Node config_node = YAML::Load(json);
        return load_config(config_node);
    }
}
