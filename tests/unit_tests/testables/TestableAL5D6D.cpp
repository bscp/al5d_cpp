
// HEADER INCLUDE
#include "TestableAL5D6D.hpp"

// TESTABLE INCLUDES
#include "TestableCommunicator.hpp"

namespace al5d
{
    TestableAL5D6D::TestableAL5D6D(CommunicatorPtr communicator_ptr)
        : AL5D6D(std::move(communicator_ptr))
    {
    }
}
