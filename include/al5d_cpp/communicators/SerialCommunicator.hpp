
#ifndef AL5D_CPP_SERIALCOMMUNICATOR_HPP
#define AL5D_CPP_SERIALCOMMUNICATOR_HPP

// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/Communicator.hpp>

namespace al5d
{
    typedef std::string SerialPort;
    
    enum SerialBaud
    {
        BAUD_9600,
    };
    
    class SerialCommunicator : public Communicator
    {
    public:
        SerialCommunicator(SerialPort serialPort, SerialBaud serialBaud);

        virtual ~SerialCommunicator() = default;
    
        void transmit(const std::string& message) final;
    };
}

#endif // AL5D_CPP_SERIALCOMMUNICATOR_HPP
