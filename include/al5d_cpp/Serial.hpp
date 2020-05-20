#ifndef AL5D_CPP_SERIAL_HPP
#define	AL5D_CPP_SERIAL_HPP

// SYSTEM INCLUDES
#include <string>

// 3TH PARTY INCLUDES
#include <boost/asio.hpp>


namespace serial
{
    typedef boost::asio::serial_port_base::stop_bits::type StopBitsType;
    typedef boost::asio::serial_port_base::parity::type ParityType;
    typedef boost::asio::serial_port_base::flow_control::type FlowControlType;
    
    typedef std::string Port;
    typedef boost::asio::serial_port_base::stop_bits StopBits;
    typedef boost::asio::serial_port_base::parity Parity;
    typedef boost::asio::serial_port_base::flow_control FlowControl;
    typedef boost::asio::serial_port_base::baud_rate BaudRate;
    typedef boost::asio::serial_port_base::character_size CharacterSize;
    
    class Serial
    {
    public:
        explicit Serial(
            const Port &port);
        
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
            const std::string& message);

    private:

        boost::asio::io_service io;
        boost::asio::serial_port serial;
    };
}


#endif	/* AL5D_CPP_SERIAL_HPP */
