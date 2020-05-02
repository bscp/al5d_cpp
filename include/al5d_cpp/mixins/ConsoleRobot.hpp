#ifndef AL5D_CPP_CONSOLECOMMUNICATOR_HPP
#define AL5D_CPP_CONSOLECOMMUNICATOR_HPP

// SYSTEM INCLUDES
#include <iostream>

// PROJECT INCLUDES
#include <al5d_cpp/interfaces/ICommunicator.hpp>


namespace al5d
{
    template <typename BaseType>
    class ConsoleRobot : public BaseType, ICommunicator
    {
    public:
        ConsoleRobot(
            const typename BaseType::Config& config)
            : BaseType(config)
        {
        }

        virtual ~ConsoleRobot() = default;
    
    protected:
        void transmit( // overrides ICommunicator
            const std::string& message)
            final
        {
            std::cout << message << "\n";
        }
    };
}


#endif // AL5D_CPP_CONSOLECOMMUNICATOR_HPP
