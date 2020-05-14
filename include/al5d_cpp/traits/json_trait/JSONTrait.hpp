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
        
        static PosingConfig posing_config_from_json(
            const std::string& json_data);

        static PosingConfig posing_config_from_json_file(
            const std::string& path);
        
        explicit JSONTrait(
            const AL5DBaseConfig& config);

        virtual ~JSONTrait();
        
    };
}


#include "JSONTrait.tpp"

#endif // AL5D_CPP_CONFIGURINGTRAIT_HPP
