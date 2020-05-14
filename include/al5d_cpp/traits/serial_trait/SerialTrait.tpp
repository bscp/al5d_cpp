#ifndef AL5D_CPP_SERIALTRAIT_TPP
#define	AL5D_CPP_SERIALTRAIT_TPP

// PROJECT INCLUDES
#include <al5d_cpp/traits/serial_trait/SerialCommunicator.hpp>


namespace al5d
{
    template <typename BaseType>
    SerialTrait<BaseType>::SerialTrait(
        const AL5DBaseConfig &config)
        : BaseType(config)
        , serial_port(config.serial_config.port)
        , serial_baud_rate(config.serial_config.baud_rate)
    {
        connect();
    }


    template <typename BaseType>
    SerialTrait<BaseType>::~SerialTrait()
    {
    }

    
    template <typename BaseType>
    void SerialTrait<BaseType>::connect()
    {
        auto ptr = SerialCommunicator::as_ptr(serial_port, serial_baud_rate);
        BaseType::set_communicator_ptr(ptr);
        sleep(2); // TODO : needed for arduino simulator, but also for real al5d?
    }
}


#endif	/* AL5D_CPP_SERIALTRAIT_TPP */
