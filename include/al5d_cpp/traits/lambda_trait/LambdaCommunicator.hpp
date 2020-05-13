#ifndef AL5D_CPP_LAMBDACOMMUNICATOR_HPP
#define	AL5D_CPP_LAMBDACOMMUNICATOR_HPP

// SYSTEM INCLUDES
#include <functional>

// PROJECT INCLUDES
#include <al5d_cpp/base/Communicator.hpp>


namespace al5d
{
    typedef std::function<void(const std::string&)> TransmitFn;

    class LambdaCommunicator : public Communicator
    {
    public:
    
        static CommunicatorPtr as_ptr();
        
        LambdaCommunicator(); // TODO : set = default?

        void transmit(
            const std::string& message)
            override;

        void set_transmit_fn(
            const TransmitFn& transmit_fn);

    private:

        TransmitFn transmit_fn;
    };
}


#endif	/* AL5D_CPP_LAMBDACOMMUNICATOR_HPP */
