// USED THESE EXAMPLES: https://github.com/fedetft/serial-port

#ifndef AL5D_CPP_SERIALROBOT_HPP
#define	AL5D_CPP_SERIALROBOT_HPP

// SYSTEM INCLUDES
#include <string>

// 3TH PARTY INCLUDES
#include <boost/asio.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/interfaces/ICommunicator.hpp>
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    template <typename BaseType>
    class SerialRobotConfig : public BaseType::Config
    {
    public:
        SerialPort serial_port = SerialPort("/dev/ttyUSB0");
        BaudRate serial_baud = BaudRate(9600);
    };


    template <typename BaseType>
    class SerialRobot : public BaseType, ICommunicator
    {
    public:
        typedef SerialRobotConfig<BaseType> Config;
       
        explicit SerialRobot(
            const Config &config);
        

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

    protected:

        void transmit( // overrides ICommunicator
            const std::string& message)
            final;

    private:

        boost::asio::io_service io;
        boost::asio::serial_port serial;
    };
}


#include "SerialRobot.tpp"

#endif	/* AL5D_CPP_SERIALROBOT_HPP */
