
#ifndef AL5D_CPP_TESTABLEAL5D6D_HPP
#define AL5D_CPP_TESTABLEAL5D6D_HPP

// PROJECT INCLUDES
#include <al5d_cpp/AL5D6D.hpp>

namespace al5d
{
    class TestableAL5D6D : public AL5D6D
    {
    public:
        explicit TestableAL5D6D(CommunicatorPtr communicator_ptr=nullptr);

        virtual ~TestableAL5D6D() = default;
    };
}

#endif // AL5D_CPP_TESTABLEAL5D6D_HPP
