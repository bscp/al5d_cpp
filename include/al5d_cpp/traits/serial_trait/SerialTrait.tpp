#ifndef AL5D_CPP_SERIALTRAIT_TPP
#define	AL5D_CPP_SERIALTRAIT_TPP

// SYSTEM INCLUDES
#include <string>

// 3TH PARTY INCLUDES
#include <boost/asio.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/traits/serial_trait/SerialTraitConfig.hpp>


namespace al5d
{
    template <typename BaseType>
    SerialTrait<BaseType>::SerialTrait(
        const Config &config)
        : BaseType(config)
        , serial(config.serial_port)
    {
        set_baud_rate(config.serial_baud);
        set_parity(config.serial_parity);
        set_flow_control(config.serial_flow_control);
        set_stop_bits(config.serial_stop_bits);
        set_character_size(config.serial_character_size);
    }
    
    
    template <typename BaseType>
    void SerialTrait<BaseType>::connect()
    {
        // TODO : implement
    }
    

    template <typename BaseType>
    bool SerialTrait<BaseType>::is_connected()
    {
        return true; // TODO : implement
    }
    

    template <typename BaseType>
    void SerialTrait<BaseType>::disconnect()
    {
        // TODO : implement
    }
}


#endif	/* AL5D_CPP_SERIALTRAIT_TPP */
