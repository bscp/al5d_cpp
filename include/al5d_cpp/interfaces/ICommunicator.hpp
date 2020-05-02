#ifndef AL5D_CPP_ICOMMUNICATOR_HPP
#define AL5D_CPP_ICOMMUNICATOR_HPP

// SYSTEM INCLUDES
#include <string>


namespace al5d
{
    class ICommunicator
    {
    public:
        ICommunicator() = default;

        virtual ~ICommunicator() = default;
    
    protected:
        virtual void transmit(
            const std::string& message) = 0;
    };
}


#endif // AL5D_CPP_ICOMMUNICATOR_HPP
