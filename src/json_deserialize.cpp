// HEADER INCLUDE
#include <al5d_cpp/traits/configurable_trait/json_deserialize.hpp>


namespace al5d
{
    namespace // anonymous namespace, these symbols are private
    {
        std::vector<Degrees> load_degrees_range(
            const YAML::Node &degrees_node)
        {
            std::vector<Degrees> degrees_range(2);
            degrees_range[0] = degrees_node[0].as<Degrees>();
            degrees_range[1] = degrees_node[1].as<Degrees>();
            return degrees_range;
        }


        std::vector<PulseWidth> load_pulse_width_range(
            const YAML::Node &pulse_width_node)
        {
            std::vector<PulseWidth> pulse_width_range(2);
            pulse_width_range[0] = pulse_width_node[0].as<PulseWidth>();
            pulse_width_range[1] = pulse_width_node[1].as<PulseWidth>();
            return pulse_width_range;
        }


        BoardChannel load_channel(
            const YAML::Node &channel_node)
        {
            return channel_node.as<BoardChannel>();
        }


        JointConfig load_joint_config(
            const YAML::Node &joint_config_node)
        {
            auto channel = load_channel(joint_config_node["board_channel"]);
            auto pulse_width_range = load_pulse_width_range(joint_config_node["pulse_width_range"]);
            auto degrees_range = load_degrees_range(joint_config_node["degrees_range"]);

            return JointConfig(
                channel,
                pulse_width_range[0],
                pulse_width_range[1],
                degrees_range[0],
                degrees_range[1]);
        }


        JointConfigs load_joint_configs(
            const YAML::Node &joint_configs_node)
        {
            JointConfigs joint_configs;

            for (auto joint_config_node : joint_configs_node)
            {
                auto joint_config = load_joint_config(joint_config_node);
                joint_configs.push_back(joint_config);
            }

            return joint_configs;
        }


        AL5DBaseConfig load_config(
            const YAML::Node &config_node)
        {
            AL5DBaseConfig config;
            config.joint_configs = load_joint_configs(config_node["joints"]);
            return config;
        }
    }


    AL5DBaseConfig load_config_from_json_file(
        const std::string& file_path)
    {
        const YAML::Node config_node = YAML::LoadFile(file_path);
        return load_config(config_node);
    }


    AL5DBaseConfig load_config_from_json(
        const std::string& json)
    {
        const YAML::Node config_node = YAML::Load(json);
        return load_config(config_node);
    }
}
