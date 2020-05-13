#ifndef AL5D_CPP_LAMBDATRAIT_HPP
#define	AL5D_CPP_LAMBDATRAIT_HPP

// SYSTEM INCLUDES
#include <functional>
#include <memory>

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>
#include <al5d_cpp/traits/lambda_trait/LambdaCommunicator.hpp>


namespace al5d
{
    typedef std::function<void(const std::string&)> TransmitFn;

    template <typename BaseType>
    class LambdaTrait : public BaseType
    {
    public:
        explicit LambdaTrait(
            const AL5DBaseConfig& config);
        
        void set_transmit_fn(
            const TransmitFn& transmit_fn);
    };

    typedef std::shared_ptr<LambdaCommunicator> LambdaCommunicatorPtr;
}


#include "LambdaTrait.tpp"

#endif	/* AL5D_CPP_LAMBDATRAIT_HPP */
