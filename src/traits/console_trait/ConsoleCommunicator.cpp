// HEADER INCLUDE
#include <al5d_cpp/traits/console_trait/ConsoleCommunicator.hpp>

// SYSTEM INCLUDES
#include <iostream>


namespace al5d
{
    /*static*/ CommunicatorPtr ConsoleCommunicator::as_ptr()
    {
        return std::make_shared<ConsoleCommunicator>();
    }

    
    void ConsoleCommunicator::transmit(
        const std::string& message)
    {
        std::cout << message;
    }
}
