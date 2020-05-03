#ifndef AL5D_CPP_SERIALROBOT_TPP
#define	AL5D_CPP_SERIALROBOT_TPP

// SYSTEM INCLUDES
#include <string>

// 3TH PARTY INCLUDES
#include <boost/asio.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/mixins/SerialRobot/SerialRobotConfig.hpp>


namespace al5d
{
    template <typename BaseType>
    SerialRobot<BaseType>::SerialRobot(
        const Config &config)
        : BaseType(config)
        , serial(config.serial_port)
    {
        set_baud_rate(config.serial_baud);
        set_parity(config.serial_parity);
        set_flow_control(config.serial_flow_control);
        set_stop_bits(config.serial_stop_bits);
        set_character_size(config.serial_character_size);
    }
}


#endif	/* AL5D_CPP_SERIALROBOT_TPP */
