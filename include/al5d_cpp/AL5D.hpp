#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// PROJECT INCLUDES
#include <al5d_cpp/AL5DBase.hpp>
#include <al5d_cpp/Duration.hpp>

// Robot mixins
#include <al5d_cpp/mixins/SerialRobot.hpp>
#include <al5d_cpp/mixins/ConsoleRobot.hpp>
#include <al5d_cpp/mixins/LambdaRobot.hpp>


namespace al5d
{
    typedef SerialRobot<AL5DBase> AL5D;
    typedef ConsoleRobot<AL5DBase> ConsoleAL5D;
    // typedef SerialRobot<Logging<Statefull<AL5DBase>>> AL5D // TODO : implement mixins
}


#endif // AL5D_CPP_AL5D_HPP
