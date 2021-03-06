#ifndef AL5D_CPP_SERIALCOMMUNICATOR_HPP
#define	AL5D_CPP_SERIALCOMMUNICATOR_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/CommunicatorBase.hpp>
#include <al5d_cpp/Serial.hpp>
#include <al5d_cpp/Timer.hpp>

#define SECONDS_TO_CONNECT 2.0


namespace al5d_cpp
{
    class SerialCommunicator : public CommunicatorBase
    {
    public:
    
        static CommunicatorBasePtr as_pointer(
            const serial::Port& port,
            const serial::BaudRate baud_rate);
        
        SerialCommunicator(
            const serial::Port& port,
            const serial::BaudRate baud_rate);

        void transmit(
            const std::string& message)
            override;
        
        bool is_connected()
            const
            override;
        
    private:

        static void log_connecting(
            const serial::Port& port,
            const serial::BaudRate baud_rate);

        serial::Serial serial;
        TimerPtr timer_ptr;
    };
}


#endif	/* AL5D_CPP_SERIALCOMMUNICATOR_HPP */
