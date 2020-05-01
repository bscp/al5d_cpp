
#ifndef AL5D_CPP_CallbackCommunicator_HPP
#define AL5D_CPP_CallbackCommunicator_HPP

// SYSTEM INCLUDES
#include <functional>

// PROJECT INCLUDES
#include <al5d_cpp/communicators/Communicator.hpp>

namespace al5d
{
    typedef std::function<void(const std::string&)> TransmitLambda;

    class LambdaCommunicator : public Communicator
    {
    public:
        static CommunicatorPtr as_pointer(
            TransmitLambda transmit_lambda);
        
        LambdaCommunicator(
            TransmitLambda transmit_lambda);

        virtual ~LambdaCommunicator() = default;
    
        void transmit(const std::string& message) final;

    private:
        TransmitLambda transmit_lambda;
    };
}

#endif // AL5D_CPP_CallbackCommunicator_HPP
