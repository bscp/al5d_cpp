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
    typedef StatefullRobot<AL5DBase> StatefullAL5D;
    typedef LoggingRobot<StatefullAL5D> LoggingStatefullAL5D;

    // SerialRobot
    typedef SerialRobot<LoggingStatefullAL5D> AL5D;

    // LambdaRobot
    typedef LambdaRobot<LoggingStatefullAL5D> LambdaAL5D;
}


#endif // AL5D_CPP_AL5D_HPP
