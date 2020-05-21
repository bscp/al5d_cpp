#ifndef AL5D_CPP_LAMBDACOMMUNICATOR_HPP
#define	AL5D_CPP_LAMBDACOMMUNICATOR_HPP

// SYSTEM INCLUDES
#include <functional>

// PROJECT INCLUDES
#include <al5d_cpp/base/Communicator.hpp>


namespace al5d_cpp
{
    typedef std::function<void(const std::string&)> TransmitFn;

    class LambdaCommunicator : public Communicator
    {
    public:
    
        static CommunicatorPtr as_pointer();
        
        LambdaCommunicator();

        void transmit(
            const std::string& message)
            override;

        void set_transmit_fn(
            const TransmitFn& transmit_fn);

    private:

        static void log_connecting();

        static void log_transmitting( // TODO : move to CommunicatorBase class
            const std::string& message);

        TransmitFn transmit_fn;
    };
}


#endif	/* AL5D_CPP_LAMBDACOMMUNICATOR_HPP */
