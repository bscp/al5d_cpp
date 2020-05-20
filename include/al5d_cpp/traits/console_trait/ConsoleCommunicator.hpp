#ifndef AL5D_CPP_CONSOLECOMMUNICATOR_HPP
#define	AL5D_CPP_CONSOLECOMMUNICATOR_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/Communicator.hpp>


namespace al5d_cpp
{
    class ConsoleCommunicator : public Communicator
    {
    public:
    
        static CommunicatorPtr as_pointer();
        
        ConsoleCommunicator()
            : Communicator()
        {
        }

        void transmit(
            const std::string& message)
            override;
    };
}


#endif	/* AL5D_CPP_CONSOLECOMMUNICATOR_HPP */
