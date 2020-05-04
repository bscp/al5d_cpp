#ifndef AL5D_CPP_SERIALTRAIT_HPP
#define	AL5D_CPP_SERIALTRAIT_HPP

// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/traits/serial_trait/SerialTraitConfig.hpp>
#include <al5d_cpp/Serial.hpp>


namespace al5d
{
    template <typename BaseType>
    class SerialTrait : public BaseType
    {
    public:
        typedef SerialTraitConfig<BaseType> Config;
       
        explicit SerialTrait(
            const Config &config);

    private:
        serial::Serial serial;
    };
}


#include "SerialTrait.tpp"

#endif	/* AL5D_CPP_SERIALTRAIT_HPP */
