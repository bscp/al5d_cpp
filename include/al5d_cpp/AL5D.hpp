#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/AL5DBase.hpp>
#include <al5d_cpp/controller/Controller.hpp>

// CONSTRUCTOR INCLUDES
#include <al5d_cpp/readers/json_reader.hpp>

// TRAIT INCLUDES
#include <al5d_cpp/traits/serial_trait/SerialTrait.hpp>
#include <al5d_cpp/traits/lambda_trait/LambdaTrait.hpp>
#include <al5d_cpp/traits/console_trait/ConsoleTrait.hpp>


namespace al5d
{
    // typedef ConsoleTrait<AL5DBase> AL5D;
    typedef SerialTrait<AL5DBase> AL5D;
    // typedef LambdaTrait<AL5DBase> AL5D;
}


#endif // AL5D_CPP_AL5D_HPP
