// TODO : make traits.hpp file in root which includes all traits

// HEADER INCLUDE
#include <al5d_cpp/traits/console_trait/ConsoleCommunicator.hpp>

// SYSTEM INCLUDES
#include <iostream>


namespace al5d
{
    /*static*/ CommunicatorPtr ConsoleCommunicator::as_pointer()
    {
        return std::make_shared<ConsoleCommunicator>();
    }

    
    void ConsoleCommunicator::transmit(
        const std::string& message)
    {
        std::cout << message;
    }
}
