#ifndef AL5D_CPP_COMMUNICATOR_HPP
#define AL5D_CPP_COMMUNICATOR_HPP

// SYSTEM INCLUDES 
#include <memory> 
#include <string>


namespace al5d
{
    class Communicator
    {
    public:
        virtual void transmit(
            const std::string& message) = 0;
    
    protected:
        Communicator() {}; // TODO : move to cpp file
    };

    typedef std::shared_ptr<Communicator> CommunicatorPtr;
}


#endif // AL5D_CPP_COMMUNICATOR_HPP
