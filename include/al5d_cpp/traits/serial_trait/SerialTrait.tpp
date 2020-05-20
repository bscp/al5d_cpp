#ifndef AL5D_CPP_SERIALTRAIT_TPP
#define	AL5D_CPP_SERIALTRAIT_TPP

// PROJECT INCLUDES
#include <al5d_cpp/traits/serial_trait/SerialCommunicator.hpp>


namespace al5d_cpp
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
        log_connecting();
        auto ptr = SerialCommunicator::as_pointer(serial_port, serial_baud_rate);
        BaseType::set_communicator_ptr(ptr);
        sleep(2); // TODO : needed for arduino simulator, but also for real al5d?
    }


    template <typename BaseType>
    void SerialTrait<BaseType>::log_connecting()
        const
    {
        const std::string method_string = "Method='Serial'";
        const std::string port_string = "Port='" + serial_port + "'";
        const std::string angle_string = "Baud='" + std::to_string(serial_baud_rate.value()) + "'";
        LOG_INFO("CONNECTING :: " + method_string + " " + port_string + " " + angle_string);
    }
}


#endif	/* AL5D_CPP_SERIALTRAIT_TPP */
