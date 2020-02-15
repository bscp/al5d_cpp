
// HEADER INCLUDE
#include <al5d_cpp/communicators/ConsoleCommunicator.hpp>

// SYSTEM INCLUDES
#include <iostream>

namespace al5d
{
    void al5d::ConsoleCommunicator::transmit(const std::string &message)
    {
        std::cout << message << "\n";
    }
}
