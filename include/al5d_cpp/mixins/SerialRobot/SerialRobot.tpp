#ifndef AL5D_CPP_SERIALROBOT_TPP
#define	AL5D_CPP_SERIALROBOT_TPP

// SYSTEM INCLUDES
#include <string>

// 3TH PARTY INCLUDES
#include <boost/asio.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/mixins/SerialRobot/SerialRobotConfig.hpp>


namespace al5d
{
    template <typename BaseType>
    SerialRobot<BaseType>::SerialRobot(
        const Config &config)
        : BaseType(config)
        , io()
        , serial(io, config.serial_port)
    {
        set_baud_rate(config.serial_baud);
        set_parity(config.serial_parity);
        set_flow_control(config.serial_flow_control);
        set_stop_bits(config.serial_stop_bits);
        set_character_size(config.serial_character_size);
    }
    

    template <typename BaseType>
    void SerialRobot<BaseType>::set_baud_rate(
        const typename Config::SerialBaudRate& baud_rate)
    {
        serial.set_option(baud_rate);
    }
    

    template <typename BaseType>
    void SerialRobot<BaseType>::set_parity(
        const typename Config::SerialParityType& parity_type)
    {
        serial.set_option(Parity(parity_type));
    }
    

    template <typename BaseType>
    void SerialRobot<BaseType>::set_flow_control(
        const typename Config::SerialFlowControlType& flow_control_type)
    {
        serial.set_option(FlowControl(flow_control_type));
    }
    

    template <typename BaseType>
    void SerialRobot<BaseType>::set_stop_bits(
        const typename Config::SerialStopBitsType& stop_bits_type)
    {
        serial.set_option(StopBits(stop_bits_type));
    }
    

    template <typename BaseType>
    void SerialRobot<BaseType>::set_character_size(
        const typename Config::SerialCharacterSize& character_size)
    {
        serial.set_option(character_size);
    }


    template <typename BaseType>
    void SerialRobot<BaseType>::transmit(
        const std::string& message)
    {
        boost::asio::write(serial, boost::asio::buffer(message.c_str(), message.size()));
    }
}


#endif	/* AL5D_CPP_SERIALROBOT_TPP */
