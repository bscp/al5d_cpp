#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/AL5DBase.hpp>
#include <al5d_cpp/Duration.hpp>

// MIXIN INCLUDES
#include <al5d_cpp/traits/logging_trait/LoggingTrait.hpp>
#include <al5d_cpp/traits/progressing_trait/ProgressingTrait.hpp>
#include <al5d_cpp/traits/serial_trait/SerialTrait.hpp>
#include <al5d_cpp/traits/json_trait/JSONTrait.hpp>


namespace al5d
{
    typedef ProgressingTrait<AL5DBase> ProgressingAL5D;
    typedef JSONTrait<ProgressingAL5D> JSONAL5D;
    typedef LoggingTrait<JSONAL5D> LoggingAL5D;

    typedef JSONAL5D SilentAL5D;
    typedef SerialTrait<SilentAL5D> AL5D;
}


#endif // AL5D_CPP_AL5D_HPP
