#ifndef AL5D_CPP_SERIALROBOTCONFIG_HPP
#define	AL5D_CPP_SERIALROBOTCONFIG_HPP

// SYSTEM INCLUDES
#include <string>

// 3TH PARTY INCLUDES
#include <boost/asio.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    template <typename BaseType>
    class SerialRobotConfig : public BaseType::Config
    {
    public:
        typedef boost::asio::serial_port_base::stop_bits::type StopBitsType;
        typedef boost::asio::serial_port_base::parity::type ParityType;
        typedef boost::asio::serial_port_base::flow_control::type FlowControlType;
        
        typedef std::string SerialPort;
        typedef boost::asio::serial_port_base::stop_bits SerialStopBits;
        typedef boost::asio::serial_port_base::parity SerialParity;
        typedef boost::asio::serial_port_base::flow_control SerialFlowControl;
        typedef boost::asio::serial_port_base::baud_rate SerialBaudRate;
        typedef boost::asio::serial_port_base::character_size SerialCharacterSize;

        SerialPort serial_port = SerialPort("/dev/ttyUSB0");
        SerialBaudRate serial_baud = SerialBaudRate(9600);
        SerialStopBits serial_stop_bits = SerialStopBits::one;
        SerialParity serial_parity = SerialParity::none;
        SerialFlowControl serial_flow_control = SerialFlowControl::none;
        SerialCharacterSize serial_character_size = 8;
    };
}


#endif	/* AL5D_CPP_SERIALROBOTCONFIG_HPP */
