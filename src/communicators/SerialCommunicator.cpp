
// HEADER INCLUDE
#include <al5d_cpp/communicators/SerialCommunicator.hpp>

// SYSTEM INCLUDES
#include <iostream>

namespace al5d
{
    /*static*/ CommunicatorPtr SerialCommunicator::as_pointer(
        const SerialPort &serial_port,
        const BaudRate &serial_baud)
    {
        return std::make_shared<SerialCommunicator>(serial_port, serial_baud);
    }
    
    
    SerialCommunicator::SerialCommunicator(
        const SerialPort &serial_port,
        const BaudRate &serial_baud)
        : io()
        , serial(io, serial_port)
    {
        set_baud_rate(serial_baud);
    }


    void SerialCommunicator::set_baud_rate(
        const BaudRate& baud_rate)
    {
        serial.set_option(baud_rate);
    }


    void SerialCommunicator::set_parity(
        const ParityType& parity_type)
    {
        serial.set_option(Parity(parity_type));
    }


    void SerialCommunicator::set_flow_control(
        const FlowControlType& flow_control_type)
    {
        serial.set_option(FlowControl(flow_control_type));
    }


    void SerialCommunicator::set_stop_bits(
        const StopBitsType& stop_bits_type)
    {
        serial.set_option(StopBits(stop_bits_type));
    }


    void SerialCommunicator::set_character_size(
        const CharacterSize& character_size)
    {
        serial.set_option(character_size);
    }


    void SerialCommunicator::transmit(
        const std::string &message)
    {
        std::cout << "TRANSMITTING :: " << message << "\n";
        boost::asio::write(serial, boost::asio::buffer(message.c_str(), message.size()));
    }
}
