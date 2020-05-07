#ifndef AL5D_CPP_CONFIGURINGTRAIT_TPP
#define	AL5D_CPP_CONFIGURINGTRAIT_TPP

// PROJECT INCLUDES
#include <al5d_cpp/traits/configurable_trait/json_deserialize.hpp>

namespace al5d
{
    template <typename BaseType>
    /*static*/ ConfigurableTrait<BaseType> ConfigurableTrait<BaseType>::from_json_file(
        const std::string& path)
    {
        auto config = al5d::load_config_from_json_file(path);
        return ConfigurableTrait<BaseType>(config);
    }


    template <typename BaseType>
    /*static*/ ConfigurableTrait<BaseType> ConfigurableTrait<BaseType>::from_json(
        const std::string& json_data)
    {
        auto config = al5d::load_config_from_json(json_data);
        return ConfigurableTrait<BaseType>(config);
    }


    template <typename BaseType>
    ConfigurableTrait<BaseType>::ConfigurableTrait(
        const Config& config)
        : BaseType(config)
    {
    }
}


#endif	/* AL5D_CPP_CONFIGURINGTRAIT_TPP */
