
// HEADER INCLUDE
#include <al5d_cpp/communicators/ConsoleCommunicator.hpp>

// SYSTEM INCLUDES
#include <iostream>

namespace al5d
{
    /*static*/ CommunicatorPtr ConsoleCommunicator::as_pointer()
    {
        return std::make_shared<ConsoleCommunicator>();
    }
    
    
    void al5d::ConsoleCommunicator::transmit(const std::string &message)
    {
        std::cout << message << "\n";
    }
}
