// HEADER INCLUDE
#include <al5d_cpp/base/configs/SerialConfig.hpp>


namespace al5d_cpp
{
    SerialConfig::SerialConfig(
        serial::Port port,
        serial::BaudRate baud_rate)
        : port(std::move(port))
        , baud_rate(std::move(baud_rate))
    {
    }
}
