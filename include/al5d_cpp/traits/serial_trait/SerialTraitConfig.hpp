#ifndef AL5D_CPP_SERIALTRAITCONFIG_HPP
#define	AL5D_CPP_SERIALTRAITCONFIG_HPP

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
    class SerialTraitConfig : public BaseType::Config
    {
    public:
        serial::Port serial_port = serial::Port("/dev/ttyUSB0");
        serial::BaudRate serial_baud = serial::BaudRate(9600);
        serial::StopBitsType serial_stop_bits = serial::StopBits::one;
        serial::ParityType serial_parity = serial::Parity::none;
        serial::FlowControlType serial_flow_control = serial::FlowControl::none;
        serial::CharacterSize serial_character_size = serial::CharacterSize(8);
    };
}


#endif	/* AL5D_CPP_SERIALTRAITCONFIG_HPP */
