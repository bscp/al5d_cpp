#ifndef AL5D_CPP_JSONREADER_HPP
#define AL5D_CPP_JSONREADER_HPP

// SYSTEM INCLUDES
#include <string>

// 3TH PARTY INCLUDES
#include <yaml-cpp/yaml.h>

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>


namespace al5d_cpp
{
    AL5DBaseConfig al5d_config_from_json_file(
        const std::string& path);

    AL5DBaseConfig al5d_config_from_json(
        const std::string& json);

    PosingConfig poses_config_from_json_file(
        const std::string& path);

    PosingConfig poses_config_from_json(
        const std::string& json);
}


#endif // AL5D_CPP_JSONREADER_HPP
