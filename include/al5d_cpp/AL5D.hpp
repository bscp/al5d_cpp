#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/AL5DBase.hpp>
#include <al5d_cpp/Duration.hpp>

// MIXIN INCLUDES
#include <al5d_cpp/traits/logging_trait/LoggingTrait.hpp>
#include <al5d_cpp/traits/progressing_trait/ProgressingTrait.hpp>
#include <al5d_cpp/traits/serial_trait/SerialTrait.hpp>
#include <al5d_cpp/traits/console_trait/ConsoleTrait.hpp>
#include <al5d_cpp/traits/json_trait/JSONTrait.hpp>
#include <al5d_cpp/base/JointTypeAngle.hpp>


namespace al5d
{
    typedef ProgressingTrait<AL5DBase> ProgressingAL5D;
    typedef LoggingTrait<ProgressingAL5D> LoggingAL5D; // TODO : gets skipped
    typedef ConsoleTrait<ProgressingAL5D> ConsoleAL5D;
    typedef SerialTrait<ProgressingAL5D> SerialAL5D;
    // typedef LambdaAL5D<ProgressingAL5D> LambdaAL5D;
    typedef JSONTrait<SerialAL5D> AL5D; // should always be last
}


#endif // AL5D_CPP_AL5D_HPP
