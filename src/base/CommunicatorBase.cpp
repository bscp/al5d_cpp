// HEADER INCLUDE
#include <al5d_cpp/base/CommunicatorBase.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>


namespace al5d_cpp
{
    CommunicatorBase::CommunicatorBase()
    {
    }


    bool CommunicatorBase::is_connected()
        const
    {
        return true; // is default
    }



    /*static*/ void CommunicatorBase::log_transmitting_(
        const std::string& message)
    {
        LOG_TRACE("TRANSMITTING :: Message='" + message + "'");
    }
}
