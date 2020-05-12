#ifndef SRC_INVALIDDEGREE_HPP
#define SRC_INVALIDDEGREE_HPP

// SYSTEM INCLUDES
#include <stdexcept>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d
{
    class InvalidDegree : public std::runtime_error
    {
    public:
        explicit InvalidDegree();
    };
}


#endif // SRC_INVALIDDEGREE_HPP
