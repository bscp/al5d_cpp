
#ifndef AL5D_CPP_COMMUNICATOR_HPP
#define AL5D_CPP_COMMUNICATOR_HPP

// SYTEM INCLUDES
#include <memory>

namespace al5d
{
    class Communicator
    {
    public:
        Communicator() = default;

        virtual ~Communicator() = default;
        
        virtual void transmit(const std::string& message) = 0;
    };
    
    typedef std::shared_ptr<Communicator> CommunicatorPtr;
}

#endif // AL5D_CPP_COMMUNICATOR_HPP
