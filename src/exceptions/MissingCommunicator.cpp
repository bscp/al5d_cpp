// HEADER INCLUDE
#include <al5d_cpp/exceptions/MissingCommunicator.hpp>

#define MESSAGE "communicator_ptr is nullptr. Use a trait like SerialTrait to set its value."


namespace al5d
{
    MissingCommunicator::MissingCommunicator()
        : runtime_error(MESSAGE)
    {
    }
}
