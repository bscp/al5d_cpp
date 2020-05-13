#ifndef AL5D_CPP_CONFIGURINGTRAIT_TPP
#define	AL5D_CPP_CONFIGURINGTRAIT_TPP

// PROJECT INCLUDES
#include <al5d_cpp/traits/json_trait/json_deserialize.hpp>

#include <iostream> // TODO : remove include


namespace al5d
{
    template <typename BaseType>
    /*static*/ JSONTrait<BaseType> JSONTrait<BaseType>::from_json_file(
        const std::string& path)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl; // TODO : remove
        
        auto config = al5d::load_config_from_json_file(path);
        return JSONTrait<BaseType>(config);
    }


    template <typename BaseType>
    /*static*/ JSONTrait<BaseType> JSONTrait<BaseType>::from_json(
        const std::string& json_data)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl; // TODO : remove
            
        auto config = al5d::load_config_from_json(json_data);
        return JSONTrait<BaseType>(config);
    }


    template <typename BaseType>
    /*static*/ PoseConfigs JSONTrait<BaseType>::pose_configs_from_json(
        const std::string& json_data)
    {
        return al5d::load_pose_configs_from_json(json_data);
    }


    template <typename BaseType>
    /*static*/ PoseConfigs JSONTrait<BaseType>::pose_configs_from_json_file(
        const std::string& path)
    {
        return al5d::load_pose_configs_from_json_file(path);
    }


    template <typename BaseType>
    JSONTrait<BaseType>::JSONTrait(
        const AL5DBaseConfig& config)
        : BaseType(config)
    {
    }
}


#endif	/* AL5D_CPP_CONFIGURINGTRAIT_TPP */
