#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/AL5DBase.hpp>
#include <al5d_cpp/Duration.hpp>

// MIXIN INCLUDES
#include <al5d_cpp/traits/logging_trait/LoggingTrait.hpp>
#include <al5d_cpp/traits/statefull_trait/StatefullTrait.hpp>
#include <al5d_cpp/traits/serial_trait/SerialTrait.hpp>
#include <al5d_cpp/traits/lambda_trait/LambdaTrait.hpp>


namespace al5d
{
    typedef LoggingTrait<AL5DBase> LoggingAL5D;
    typedef StatefullTrait<LoggingAL5D> StatefullLoggingAL5D;

    typedef SerialTrait<StatefullLoggingAL5D> AL5D;
    typedef LambdaTrait<StatefullLoggingAL5D> LambdaAL5D;
}


#endif // AL5D_CPP_AL5D_HPP
