// HEADER INCLUDE
#include <al5d_cpp/base/SerialConfig.hpp>


namespace al5d
{
    SerialConfig::SerialConfig(
        serial::Port port,
        serial::BaudRate baud_rate)
        : port(std::move(port))
        , baud_rate(std::move(baud_rate))
    {
    }
}
