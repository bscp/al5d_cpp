// USED EXAMPLES: https://github.com/fedetft/serial-port

#ifndef AL5D_CPP_SERIALCOMMUNICATOR_HPP
#define	AL5D_CPP_SERIALCOMMUNICATOR_HPP

// SYSTEM INCLUDES
#include <string>

// 3TH PARTY INCLUDES
#include <boost/asio.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/communicators/Communicator.hpp>
#include <al5d_cpp/types.hpp>

namespace al5d
{
    class SerialCommunicator : public Communicator
    {
    public:
        static CommunicatorPtr as_pointer(
            const SerialPort &serial_port,
            const BaudRate &serial_baud=BaudRate(9600));
        
        explicit SerialCommunicator(
            const SerialPort &serial_port,
            const BaudRate &serial_baud);
        
        void set_baud_rate(
            const BaudRate& baud_rate);
        
        void set_parity(
            const ParityType& parity_type);
        
        void set_flow_control(
            const FlowControlType& flow_control_type);
        
        void set_stop_bits(
            const StopBitsType& stop_bits_type);
        
        void set_character_size(
            const CharacterSize& character_size);
        
        void transmit(
            const std::string& message)
            final;

    private:
        boost::asio::io_service io;
        boost::asio::serial_port serial;
    };
}

#endif	/* AL5D_CPP_SERIALCOMMUNICATOR_HPP */
