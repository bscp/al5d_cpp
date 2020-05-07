#ifndef AL5D_CPP_JSONDESERIALIZE_HPP
#define AL5D_CPP_JSONDESERIALIZE_HPP

// SYSTEM INCLUDES
#include <string>

// 3TH PARTY INCLUDES
#include <yaml-cpp/yaml.h>

// PROJECT INCLUDES
#include <al5d_cpp/base/AL5DBaseConfig.hpp>


namespace al5d
{
    AL5DBaseConfig load_config_from_json_file(
        const std::string& path);

    AL5DBaseConfig load_config_from_json(
        const std::string& json);
}


#endif // AL5D_CPP_JSONDESERIALIZE_HPP
