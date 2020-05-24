#ifndef AL5D_CPP_COMMUNICATORBASE_HPP
#define AL5D_CPP_COMMUNICATORBASE_HPP

// SYSTEM INCLUDES 
#include <memory> 
#include <string>


namespace al5d_cpp
{
    class CommunicatorBase
    {
    public:
    
        virtual void transmit(
            const std::string& message) = 0;
            
        virtual bool is_connected()
            const;
    
    protected:

        CommunicatorBase();

        static void log_transmitting_(
            const std::string& message);
    };

    typedef std::shared_ptr<CommunicatorBase> CommunicatorBasePtr;
}


#endif // AL5D_CPP_COMMUNICATORBASE_HPP
