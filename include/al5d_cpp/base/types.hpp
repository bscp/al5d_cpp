#ifndef AL5D_CPP_TYPES_HPP
#define AL5D_CPP_TYPES_HPP

// SYSTEM INCLUDES
#include <cstdint>

// 3TH PARTY INCLUDES
#include <boost/asio.hpp>


namespace al5d
{
    typedef uint16_t PulseWidth;
    typedef uint8_t BoardChannel;
    typedef int16_t Degrees;
    
    typedef boost::asio::serial_port_base::stop_bits::type StopBitsType;
    typedef boost::asio::serial_port_base::parity::type ParityType;
    typedef boost::asio::serial_port_base::flow_control::type FlowControlType;
    
    typedef std::string SerialPort;
    typedef boost::asio::serial_port_base::stop_bits StopBits;
    typedef boost::asio::serial_port_base::parity Parity;
    typedef boost::asio::serial_port_base::flow_control FlowControl;
    typedef boost::asio::serial_port_base::baud_rate BaudRate;
    typedef boost::asio::serial_port_base::character_size CharacterSize;
}


#endif // AL5D_CPP_TYPES_HPP
