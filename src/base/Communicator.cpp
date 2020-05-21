// HEADER INCLUDE
#include <al5d_cpp/base/Communicator.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>


namespace al5d_cpp
{
    Communicator::Communicator()
    {
    }


    bool Communicator::is_connected()
        const
    {
        return true; // is default
    }



    /*static*/ void Communicator::log_transmitting_(
        const std::string& message)
    {
        LOG_INFO("TRANSMITTING :: Message='" + message + "'");
    }
}
