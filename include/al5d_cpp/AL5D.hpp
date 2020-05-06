#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/AL5DBase.hpp>
#include <al5d_cpp/Duration.hpp>

// MIXIN INCLUDES
#include <al5d_cpp/traits/logging_trait/LoggingTrait.hpp>
#include <al5d_cpp/traits/progressing_trait/ProgressingTrait.hpp>
#include <al5d_cpp/traits/serial_trait/SerialTrait.hpp>


namespace al5d
{
    typedef LoggingTrait<AL5DBase> LoggingAL5D;
    typedef ProgressingTrait<LoggingAL5D> ProgressingLoggingAL5D;
    typedef SerialTrait<ProgressingLoggingAL5D> AL5D;
}


#endif // AL5D_CPP_AL5D_HPP
