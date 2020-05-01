
// HEADER INCLUDE
#include <al5d_cpp/communicators/LambdaCommunicator.hpp>


namespace al5d
{
    /*static*/ CommunicatorPtr LambdaCommunicator::as_pointer(
        TransmitLambda transmit_lambda)
    {
        return std::make_shared<LambdaCommunicator>(transmit_lambda);
    }
    
        
    LambdaCommunicator::LambdaCommunicator(
        TransmitLambda transmit_lambda)
        : Communicator()
        , transmit_lambda(transmit_lambda)
    {
    }

    
    void LambdaCommunicator::transmit(const std::string &message)
    {
        transmit_lambda(message);
    }
}
