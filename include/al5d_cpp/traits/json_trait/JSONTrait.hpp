#ifndef AL5D_CPP_CONFIGURINGTRAIT_HPP
#define AL5D_CPP_CONFIGURINGTRAIT_HPP

// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>


namespace al5d
{
    template <typename BaseType>
    class JSONTrait : public BaseType
    {
    public:
        static JSONTrait<BaseType> from_json_file(
            const std::string& path);

        static JSONTrait<BaseType> from_json(
            const std::string& json);

        static PoseConfigs pose_configs_from_json_file(
            const std::string& path);

        static PoseConfigs pose_configs_from_json(
            const std::string& json);

        explicit JSONTrait(
            const AL5DBaseConfig& config);

        virtual ~JSONTrait() = default;
        
    };
}


#include "JSONTrait.tpp"

#endif // AL5D_CPP_CONFIGURINGTRAIT_HPP
