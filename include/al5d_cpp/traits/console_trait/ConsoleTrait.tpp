#ifndef AL5D_CPP_CONSOLETRAIT_TPP
#define	AL5D_CPP_CONSOLETRAIT_TPP

// SYSTEM INCLUDES
#include <iostream>

// PROJECT INCLUDES
#include <al5d_cpp/traits/console_trait/ConsoleCommunicator.hpp>


namespace al5d_cpp
{
    template <typename BaseType>
    ConsoleTrait<BaseType>::ConsoleTrait(
        const AL5DBaseConfig& config)
        : BaseType(config)
    {
        auto ptr = ConsoleCommunicator::as_pointer();
        BaseType::set_communicator_ptr(ptr);
    }


    template <typename BaseType>
    void ConsoleTrait<BaseType>::transmit_command_terminator_()
        const
    {
        BaseType::transmit_command_terminator_();
        std::cout << std::endl; // otherwise nothing gets printed...
    }
}


#endif	/* AL5D_CPP_CONSOLETRAIT_TPP */
