
// HEADER INCLUDE
#include <al5d_cpp/communicators/SerialCommunicator.hpp>

namespace al5d
{
    /*static*/ CommunicatorPtr SerialCommunicator::as_pointer(
        const SerialPort &serial_port)
    {
        return std::make_shared<SerialCommunicator>(serial_port);
    }
    
    
    SerialCommunicator::SerialCommunicator(
        const SerialPort &serial_port)
        : serial(io, serial_port)
        , io()
    {
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
        boost::asio::write(serial, boost::asio::buffer(message.c_str(), message.size()));
    }
}
