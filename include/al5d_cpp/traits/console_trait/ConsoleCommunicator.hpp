#ifndef AL5D_CPP_CONSOLECOMMUNICATOR_HPP
#define	AL5D_CPP_CONSOLECOMMUNICATOR_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/CommunicatorBase.hpp>


namespace al5d_cpp
{
    class ConsoleCommunicator : public CommunicatorBase
    {
    public:
    
        static CommunicatorBasePtr as_pointer();
        
        ConsoleCommunicator()
            : CommunicatorBase()
        {
        }

        void transmit(
            const std::string& message)
            override;

    private:

        static void log_connecting();
    };
}


#endif	/* AL5D_CPP_CONSOLECOMMUNICATOR_HPP */
