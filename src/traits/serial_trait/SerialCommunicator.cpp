// HEADER INCLUDE
#include <al5d_cpp/traits/serial_trait/SerialCommunicator.hpp>


namespace al5d
{
    /*static*/ CommunicatorPtr SerialCommunicator::as_pointer(
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
