#ifndef AL5D_CPP_SERIALROBOT_HPP
#define	AL5D_CPP_SERIALROBOT_HPP

// SYSTEM INCLUDES
#include <string>

// 3TH PARTY INCLUDES
#include <boost/asio.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/mixins/SerialRobot/SerialRobotConfig.hpp>


namespace al5d
{
    template <typename BaseType>
    class SerialRobot : public BaseType
    {
    public:
        typedef SerialRobotConfig<BaseType> Config;
       
        explicit SerialRobot(
            const Config &config);
        

        void set_baud_rate(
            const typename Config::SerialBaudRate& baud_rate);
        

        void set_parity(
            const typename Config::SerialParityType& parity_type);
        

        void set_flow_control(
            const typename Config::SerialFlowControlType& flow_control_type);
        

        void set_stop_bits(
            const typename Config::SerialStopBitsType& stop_bits_type);
        

        void set_character_size(
            const typename Config::SerialCharacterSize& character_size);

    protected:

        void transmit( // overrides ICommunicator
            const std::string& message)
            override;

    private:

        boost::asio::io_service io;
        boost::asio::serial_port serial;
    };
}


#include "SerialRobot.tpp"

#endif	/* AL5D_CPP_SERIALROBOT_HPP */
