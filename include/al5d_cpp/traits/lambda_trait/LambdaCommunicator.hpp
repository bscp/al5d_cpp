#ifndef AL5D_CPP_LAMBDACOMMUNICATOR_HPP
#define	AL5D_CPP_LAMBDACOMMUNICATOR_HPP

// SYSTEM INCLUDES
#include <functional>

// PROJECT INCLUDES
#include <al5d_cpp/base/CommunicatorBase.hpp>


namespace al5d_cpp
{
    typedef std::function<void(const std::string&)> TransmitFn;

    class LambdaCommunicator : public CommunicatorBase
    {
    public:
    
        static CommunicatorBasePtr as_pointer();
        
        LambdaCommunicator();

        void transmit(
            const std::string& message)
            override;

        void set_transmit_fn(
            const TransmitFn& transmit_fn);

    private:

        static void log_connecting();

        TransmitFn transmit_fn;
    };
}


#endif	/* AL5D_CPP_LAMBDACOMMUNICATOR_HPP */
