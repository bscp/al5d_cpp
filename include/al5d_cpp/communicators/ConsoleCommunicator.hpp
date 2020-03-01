
#ifndef AL5D_CPP_CONSOLECOMMUNICATOR_HPP
#define AL5D_CPP_CONSOLECOMMUNICATOR_HPP

// PROJECT INCLUDES
#include <al5d_cpp/communicators/Communicator.hpp>

namespace al5d
{
    class ConsoleCommunicator : public Communicator
    {
    public:
        static CommunicatorPtr as_pointer();
        
        ConsoleCommunicator() = default;

        virtual ~ConsoleCommunicator() = default;
    
        void transmit(const std::string& message) final;
    };
}

#endif // AL5D_CPP_CONSOLECOMMUNICATOR_HPP
