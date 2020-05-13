// HEADER INCLUDE
#include <al5d_cpp/traits/lambda_trait/LambdaCommunicator.hpp>


namespace al5d
{
    /*static*/ CommunicatorPtr LambdaCommunicator::as_ptr()
    {
        return std::make_shared<LambdaCommunicator>();
    }


    LambdaCommunicator::LambdaCommunicator()
        : Communicator() 
    {
    }

    
    void LambdaCommunicator::transmit(
        const std::string& message)
    {
        if (transmit_fn != nullptr)
        {
            transmit_fn(message);
        }
    }


    void LambdaCommunicator::set_transmit_fn(
        const TransmitFn& transmit_fn)
    {
        this->transmit_fn = transmit_fn;
    }
}
