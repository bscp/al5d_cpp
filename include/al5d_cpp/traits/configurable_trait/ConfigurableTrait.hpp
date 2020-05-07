#ifndef AL5D_CPP_CONFIGURINGTRAIT_HPP
#define AL5D_CPP_CONFIGURINGTRAIT_HPP

// SYSTEM INCLUDES
#include <string>


namespace al5d
{
    template <typename BaseType>
    class ConfigurableTrait : public BaseType
    {
    public:

        typedef typename ConfigurableTrait<BaseType>::Config
            Config;

        static ConfigurableTrait<BaseType> from_json_file(
            const std::string& path);

        static ConfigurableTrait<BaseType> from_json(
            const std::string& json);

        explicit ConfigurableTrait(
            const Config& config);

        virtual ~ConfigurableTrait() = default;
        
    };
}


#include "ConfigurableTrait.tpp"

#endif // AL5D_CPP_CONFIGURINGTRAIT_HPP
