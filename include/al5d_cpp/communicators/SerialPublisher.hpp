//// https://github.com/fedetft/serial-port/tree/master/2_with_timeout
//
//#ifndef SSC32_SERIALPUBLISHER_HPP
//#define SSC32_SERIALPUBLISHER_HPP
//
//// SYSTEM INCLUDES
//#include <stdexcept>
//#include <cstdint>
//
//// 3TH PARTY INCLUDES
//#include <boost/asio.hpp>
//#include <boost/utility.hpp>
//
//namespace al5d
//{
//    enum Baudrate
//    {
//        BAUD_9600=9600,
//    };
//
//    enum Parity
//    {
//        PARITY_NONE,
//        PARITY_ODD,
//        PARITY_EVEN,
//    };
//
//    enum FlowControl
//    {
//        FLOW_CONTROL_NONE,
//        FLOW_CONTROL_HARDWARE,
//        FLOW_CONTROL_SOFTWARE,
//    };
//
//    enum StopBit
//    {
//        STOP_BIT_ONE,
//        STOP_BIT_ONE_POINT_FIVE,
//        STOP_BIT_TWO,
//    };
//
//    struct SerialConfig
//    {
//        std::string port_name;
//        Baudrate baudrate;
//        Parity parity;
//        uint8_t character_size; // 5-8
//        FlowControl flow_control;
//        StopBit stop_bit;
//
//        SerialConfig()
//            : port_name()
//            , baudrate(BAUD_9600)
//            , parity(PARITY_NONE)
//            , character_size(8)
//            , flow_control(FLOW_CONTROL_NONE)
//            , stop_bit(STOP_BIT_ONE)
//        {
//        }
//    };
//
//    class Serial
//    {
//    public:
//        explicit Serial(const SerialConfig &capabilities=SerialConfig());
//
//        virtual ~Serial() = default;
//
//        void open(const SerialConfig &capabilities);
//
//        void transmit_command(const std::string &message);
//
//        char receive();
//
//        bool is_open() const;
//
//        void close();
//    };
//}
//
//#endif // SSC32_SERIALPUBLISHER_HPP
