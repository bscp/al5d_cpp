#ifndef AL5D_CPP_CONFIGURINGTRAIT_TPP
#define	AL5D_CPP_CONFIGURINGTRAIT_TPP

// PROJECT INCLUDES
#include <al5d_cpp/traits/json_trait/json_deserialize.hpp>

namespace al5d
{
    template <typename BaseType>
    /*static*/ JSONTrait<BaseType> JSONTrait<BaseType>::from_json_file(
        const std::string& path)
    {
        auto config = al5d::load_config_from_json_file(path);
        return JSONTrait<BaseType>(config);
    }


    template <typename BaseType>
    /*static*/ JSONTrait<BaseType> JSONTrait<BaseType>::from_json(
        const std::string& json_data)
    {
        auto config = al5d::load_config_from_json(json_data);
        return JSONTrait<BaseType>(config);
    }


    template <typename BaseType>
    JSONTrait<BaseType>::JSONTrait(
        const Config& config)
        : BaseType(config)
    {
    }
}


#endif	/* AL5D_CPP_CONFIGURINGTRAIT_TPP */
