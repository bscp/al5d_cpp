#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/AL5DBase.hpp>
#include <al5d_cpp/Duration.hpp>

// MIXIN INCLUDES
#include <al5d_cpp/mixins/LoggingRobot/LoggingRobot.hpp>
#include <al5d_cpp/mixins/SerialRobot/SerialRobot.hpp>
#include <al5d_cpp/mixins/LambdaRobot/LambdaRobot.hpp>


namespace al5d
{
    // GeneralMixins
    typedef LoggingRobot<AL5DBase> LoggingAL5D;
    // typedef StatefullRobot<AL5DBase> AL5D; // TODO : implement this

    // SerialRobot
    typedef SerialRobot<LoggingAL5D> AL5D;

    // LambdaRobot
    typedef LambdaRobot<LoggingAL5D> LambdaAL5D;
}


#endif // AL5D_CPP_AL5D_HPP
