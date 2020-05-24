#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/AL5DBase.hpp>
#include <al5d_cpp/controller/Controller.hpp>
#include <al5d_cpp/controller/commands.hpp>
#include <al5d_cpp/readers.hpp>
#include <al5d_cpp/traits.hpp>


namespace al5d_cpp
{
    // typedef ConsoleTrait<AL5DBase> AL5D;
    typedef SerialTrait<AL5DBase> AL5D;
    // typedef LambdaTrait<AL5DBase> AL5D;
}


#endif // AL5D_CPP_AL5D_HPP
