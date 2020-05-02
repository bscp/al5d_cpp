#ifndef AL5D_CPP_CallbackCommunicator_HPP
#define AL5D_CPP_CallbackCommunicator_HPP

// SYSTEM INCLUDES
#include <functional>

// PROJECT INCLUDES
#include <al5d_cpp/interfaces/ICommunicator.hpp>


namespace al5d
{
    typedef std::function<void(const std::string&)> TransmitLambda;

    template <typename BaseType>
    class LambdaCommunicator : public BaseType, ICommunicator
    {
    public:
        LambdaCommunicator(
            const typename BaseType::Config& config,
            TransmitLambda transmit_lambda)
            : BaseType(config)
            , transmit_lambda(transmit_lambda)
        {
        }


        virtual ~LambdaCommunicator() = default;
    
    protected:
        void transmit( // overrides ICommunicator
            const std::string& message)
            final
        {
            transmit_lambda(message);
        }

    private:
        TransmitLambda transmit_lambda;
    };
}


#endif // AL5D_CPP_CallbackCommunicator_HPP
