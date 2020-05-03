#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/AL5DBase.hpp>
#include <al5d_cpp/Duration.hpp>

// MIXIN INCLUDES
#include <al5d_cpp/mixins/LoggingRobot/LoggingRobot.hpp>
#include <al5d_cpp/mixins/StatefullRobot/StatefullRobot.hpp>
#include <al5d_cpp/mixins/SerialRobot/SerialRobot.hpp>
#include <al5d_cpp/mixins/LambdaRobot/LambdaRobot.hpp>


namespace al5d
{
    // GeneralMixins
    typedef LoggingRobot<AL5DBase> LoggingAL5D;
    typedef StatefullRobot<LoggingAL5D> StatefullLoggingAL5D;

    // SerialRobot
    typedef SerialRobot<StatefullLoggingAL5D> AL5D;
    typedef LambdaRobot<StatefullLoggingAL5D> LambdaAL5D;
}


#endif // AL5D_CPP_AL5D_HPP
