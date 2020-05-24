// TODO : make traits.hpp file in root which includes all traits

// HEADER INCLUDE
#include <al5d_cpp/traits/console_trait/ConsoleCommunicator.hpp>

// SYSTEM INCLUDES
#include <iostream>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>


namespace al5d_cpp
{
    /*static*/ CommunicatorBasePtr ConsoleCommunicator::as_pointer()
    {
        log_connecting();
        return std::make_shared<ConsoleCommunicator>();
    }


    /*static*/ void ConsoleCommunicator::log_connecting()
    {
        LOG_INFO("CONNECTING :: Medium='Console'");
    }

    
    void ConsoleCommunicator::transmit(
        const std::string& message)
    {
        log_transmitting_(message);
        std::cout << message;
    }
}
