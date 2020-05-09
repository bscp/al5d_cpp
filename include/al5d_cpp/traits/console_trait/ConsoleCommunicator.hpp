#ifndef AL5D_CPP_CONSOLECOMMUNICATOR_HPP
#define	AL5D_CPP_CONSOLECOMMUNICATOR_HPP

// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/base/Communicator.hpp>


namespace al5d
{
    class ConsoleCommunicator : public Communicator
    {
    public:
        static CommunicatorPtr as_ptr();
        
        ConsoleCommunicator()
            : Communicator() {} // TODO

        void transmit(
            const std::string& message)
            override;
    };
}


#endif	/* AL5D_CPP_CONSOLECOMMUNICATOR_HPP */
