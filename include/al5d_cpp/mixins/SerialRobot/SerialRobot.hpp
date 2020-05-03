#ifndef AL5D_CPP_SERIALROBOT_HPP
#define	AL5D_CPP_SERIALROBOT_HPP

// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/mixins/SerialRobot/SerialRobotConfig.hpp>
#include <al5d_cpp/Serial.hpp>


namespace al5d
{
    template <typename BaseType>
    class SerialRobot : public BaseType
    {
    public:
        typedef SerialRobotConfig<BaseType> Config;
       
        explicit SerialRobot(
            const Config &config);

    private:
        serial::Serial serial;
    };
}


#include "SerialRobot.tpp"

#endif	/* AL5D_CPP_SERIALROBOT_HPP */
