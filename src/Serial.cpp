// HEADER INCLUDE
#include <al5d_cpp/Serial.hpp>


namespace serial
{
    Serial::Serial(
        const Port &port)
        : io()
        , serial(io, port)
    {
    }

    
    void Serial::set_baud_rate(
        const BaudRate& baud_rate)
    {
        serial.set_option(baud_rate);
    }
    

    void Serial::set_parity(
        const ParityType& parity_type)
    {
        serial.set_option(Parity(parity_type));
    }
    

    void Serial::set_flow_control(
        const FlowControlType& flow_control_type)
    {
        serial.set_option(FlowControl(flow_control_type));
    }
    

    void Serial::set_stop_bits(
        const StopBitsType& stop_bits_type)
    {
        serial.set_option(StopBits(stop_bits_type));
    }
    

    void Serial::set_character_size(
        const CharacterSize& character_size)
    {
        serial.set_option(character_size);
    }


    void Serial::transmit(
        const std::string& message)
    {
        boost::asio::write(serial, boost::asio::buffer(message.c_str(), message.size()));
    }
}
