#ifndef AL5D_CPP_SERIALROBOTCONFIG_HPP
#define	AL5D_CPP_SERIALROBOTCONFIG_HPP

// SYSTEM INCLUDES
#include <string>

// 3TH PARTY INCLUDES
#include <boost/asio.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>
#include <al5d_cpp/Serial.hpp>


namespace al5d
{
    template <typename BaseType>
    class SerialRobotConfig : public BaseType::Config
    {
    public:
        serial::Port serial_port = serial::Port("/dev/ttyUSB0");
        serial::BaudRate serial_baud = serial::BaudRate(9600);
        serial::StopBits serial_stop_bits = serial::StopBits::one;
        serial::Parity serial_parity = serial::Parity::none;
        serial::FlowControl serial_flow_control = serial::FlowControl::none;
        serial::CharacterSize serial_character_size = 8;
    };
}


#endif	/* AL5D_CPP_SERIALROBOTCONFIG_HPP */
