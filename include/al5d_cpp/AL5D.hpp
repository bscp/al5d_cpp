#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/AL5DBase.hpp>
#include <al5d_cpp/controller/Controller.hpp>


// TRAIT INCLUDES
#include <al5d_cpp/traits/serial_trait/SerialTrait.hpp>
#include <al5d_cpp/traits/lambda_trait/LambdaTrait.hpp>
#include <al5d_cpp/traits/console_trait/ConsoleTrait.hpp>
#include <al5d_cpp/traits/pose_trait/PoseTrait.hpp>
#include <al5d_cpp/traits/json_trait/JSONTrait.hpp>


namespace al5d
{
    typedef PoseTrait<AL5DBase> PoseAL5D;
    typedef ConsoleTrait<PoseAL5D> ConsoleAL5D;
    typedef SerialTrait<PoseAL5D> SerialAL5D;
    typedef LambdaTrait<PoseAL5D> LambdaAL5D;
    typedef JSONTrait<SerialAL5D> AL5D; // should always be last
}


#endif // AL5D_CPP_AL5D_HPP
