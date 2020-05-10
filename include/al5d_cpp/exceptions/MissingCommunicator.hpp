#ifndef SRC_MISSINGCOMMUNICATOREXCEPTION_HPP
#define SRC_MISSINGCOMMUNICATOREXCEPTION_HPP

// SYSTEM INCLUDES
#include <stdexcept>


namespace al5d
{
    class MissingCommunicator : public std::runtime_error
    {
    public:
        MissingCommunicator();
    };
}


#endif // SRC_MISSINGCOMMUNICATOREXCEPTION_HPP