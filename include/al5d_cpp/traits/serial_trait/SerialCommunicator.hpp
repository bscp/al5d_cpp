#ifndef AL5D_CPP_SERIALCOMMUNICATOR_HPP
#define	AL5D_CPP_SERIALCOMMUNICATOR_HPP

// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/base/Communicator.hpp>
#include <al5d_cpp/Serial.hpp>


namespace al5d
{
    class SerialCommunicator : public Communicator
    {
    public:
        static CommunicatorPtr as_ptr(
            const serial::Port& port,
            const serial::BaudRate baud_rate);
        
        SerialCommunicator(
            const serial::Port& port,
            const serial::BaudRate baud_rate);

        void transmit(
            const std::string& message)
            override;
        
    private:
        serial::Serial serial;
    };
}


#endif	/* AL5D_CPP_SERIALCOMMUNICATOR_HPP */
