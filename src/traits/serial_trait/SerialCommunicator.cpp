// HEADER INCLUDE
#include <al5d_cpp/traits/serial_trait/SerialCommunicator.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>


namespace al5d_cpp
{
    /*static*/ CommunicatorPtr SerialCommunicator::as_pointer(
        const serial::Port& port,
        const serial::BaudRate baud_rate)
    {
        log_connecting(port, baud_rate);
        return std::make_shared<SerialCommunicator>(port, baud_rate);
    }


    /*static*/ void SerialCommunicator::log_connecting(
        const serial::Port& port,
        const serial::BaudRate baud_rate)
    {
        const std::string method_string = "Method='Serial'";
        const std::string port_string = "Port='" + port + "'";
        const std::string angle_string = "Baud='" + std::to_string(baud_rate.value()) + "'";
        LOG_INFO("CONNECTING :: " + method_string + " " + port_string + " " + angle_string);
    }
        
    
    SerialCommunicator::SerialCommunicator(
        const serial::Port& port,
        const serial::BaudRate baud_rate)
        : serial(port)
    {
        serial.set_baud_rate(baud_rate);
        timer_ptr = Timer::as_pointer(SECONDS_TO_CONNECT);
    }

    
    void SerialCommunicator::transmit(
        const std::string& message)
    {
        serial.transmit(message);
    }
    
    
    bool SerialCommunicator::is_connected()
        const
    {
        return timer_ptr->has_elapsed();
    }
}
