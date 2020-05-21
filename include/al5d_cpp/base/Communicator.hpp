#ifndef AL5D_CPP_COMMUNICATOR_HPP
#define AL5D_CPP_COMMUNICATOR_HPP

// SYSTEM INCLUDES 
#include <memory> 
#include <string>


namespace al5d_cpp
{
    class Communicator // TODO : rename to CommunicatorBase
    {
    public:
    
        virtual void transmit(
            const std::string& message) = 0;
            
        virtual bool is_connected()
            const;
    
    protected:

        Communicator();

        static void log_transmitting_(
            const std::string& message);
    };

    typedef std::shared_ptr<Communicator> CommunicatorPtr;
}


#endif // AL5D_CPP_COMMUNICATOR_HPP
