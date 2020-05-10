// HEADER INCLUDE
#include <al5d_cpp/traits/serial_trait/SerialCommunicator.hpp>


namespace al5d
{
    /*static*/ CommunicatorPtr SerialCommunicator::as_ptr(
        const serial::Port& port,
        const serial::BaudRate baud_rate)
    {
        return std::make_shared<SerialCommunicator>(port, baud_rate);
    }
        
    
    SerialCommunicator::SerialCommunicator(
        const serial::Port& port,
        const serial::BaudRate baud_rate)
        : serial(port)
    {
        serial.set_baud_rate(baud_rate);
    }

    
    void SerialCommunicator::transmit(
        const std::string& message)
    {
        serial.transmit(message);
    }
}
