#ifndef AL5D_CPP_SERIALCONFIG_HPP
#define AL5D_CPP_SERIALCONFIG_HPP

// PROJECT INCLUDES
#include <al5d_cpp/Serial.hpp>

namespace al5d
{
    struct SerialConfig
    {
        SerialConfig(
            serial::Port port,
            serial::BaudRate baud_rate);
        
        const serial::Port port;
        const serial::BaudRate baud_rate;
    };
}


#endif // AL5D_CPP_SERIALCONFIG_HPP
