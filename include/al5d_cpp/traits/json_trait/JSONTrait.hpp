#ifndef AL5D_CPP_CONFIGURINGTRAIT_HPP
#define AL5D_CPP_CONFIGURINGTRAIT_HPP

// SYSTEM INCLUDES
#include <string>


namespace al5d
{
    template <typename BaseType>
    class JSONTrait : public BaseType
    {
    public:

        typedef typename JSONTrait<BaseType>::Config
            Config;

        static JSONTrait<BaseType> from_json_file(
            const std::string& path);

        static JSONTrait<BaseType> from_json(
            const std::string& json);

        explicit JSONTrait(
            const Config& config);

        virtual ~JSONTrait() = default;
        
    };
}


#include "JSONTrait.tpp"

#endif // AL5D_CPP_CONFIGURINGTRAIT_HPP
