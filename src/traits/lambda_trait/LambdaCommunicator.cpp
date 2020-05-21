// HEADER INCLUDE
#include <al5d_cpp/traits/lambda_trait/LambdaCommunicator.hpp>

// PROJECT INCLUDES
#include <al5d_cpp/logging.hpp>


namespace al5d_cpp
{
    /*static*/ CommunicatorPtr LambdaCommunicator::as_pointer()
    {
        log_connecting();
        return std::make_shared<LambdaCommunicator>();
    }


    LambdaCommunicator::LambdaCommunicator()
        : Communicator() 
    {
    }


    /*static*/ void LambdaCommunicator::log_connecting()
    {
        LOG_INFO("CONNECTING :: Medium='Lambda'");
    }


    /*static*/ void LambdaCommunicator::log_transmitting(
        const std::string& message)
    {
        LOG_INFO("TRANSMITTING :: Message='" + message + "'");
    }

    
    void LambdaCommunicator::transmit(
        const std::string& message)
    {
        if (transmit_fn != nullptr)
        {
            log_transmitting(message);
            transmit_fn(message);
        }
    }


    void LambdaCommunicator::set_transmit_fn(
        const TransmitFn& transmit_fn)
    {
        this->transmit_fn = transmit_fn;
    }
}
