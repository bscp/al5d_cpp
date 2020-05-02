#ifndef AL5D_CPP_SERIALROBOT_TPP
#define	AL5D_CPP_SERIALROBOT_TPP


namespace al5d
{
    template <typename BaseType>
    SerialRobot<BaseType>::SerialRobot(
        const Config &config)
        : BaseType(config)
        , io()
        , serial(io, config.serial_port)
    {
        set_baud_rate(config.serial_baud);
    }
    

    template <typename BaseType>
    void SerialRobot<BaseType>::set_baud_rate(
        const BaudRate& baud_rate)
    {
        serial.set_option(baud_rate);
    }
    

    template <typename BaseType>
    void SerialRobot<BaseType>::set_parity(
        const ParityType& parity_type)
    {
        serial.set_option(Parity(parity_type));
    }
    

    template <typename BaseType>
    void SerialRobot<BaseType>::set_flow_control(
        const FlowControlType& flow_control_type)
    {
        serial.set_option(FlowControl(flow_control_type));
    }
    

    template <typename BaseType>
    void SerialRobot<BaseType>::set_stop_bits(
        const StopBitsType& stop_bits_type)
    {
        serial.set_option(StopBits(stop_bits_type));
    }
    

    template <typename BaseType>
    void SerialRobot<BaseType>::set_character_size(
        const CharacterSize& character_size)
    {
        serial.set_option(character_size);
    }


    template <typename BaseType>
    void SerialRobot<BaseType>::transmit(
        const std::string& message)
    {
        boost::asio::write(serial, boost::asio::buffer(message.c_str(), message.size()));
    }
}


#endif	/* AL5D_CPP_SERIALROBOT_TPP */
