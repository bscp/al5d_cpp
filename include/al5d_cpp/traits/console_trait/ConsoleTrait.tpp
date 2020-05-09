#ifndef AL5D_CPP_CONSOLETRAIT_TPP
#define	AL5D_CPP_CONSOLETRAIT_TPP

// SYSTEM INCLUDES
#include <string>
#include <iostream>

// PROJECT INCLUDES
#include <al5d_cpp/traits/console_trait/ConsoleCommunicator.hpp>


namespace al5d
{
    template <typename BaseType>
    ConsoleTrait<BaseType>::ConsoleTrait(
        const Config &config)
        : BaseType(config)
    {
        auto ptr = ConsoleCommunicator::as_ptr();
        BaseType::set_communicator_ptr(ptr);
    }


    template <typename BaseType>
    void ConsoleTrait<BaseType>::terminate_command()
        const
    {
        BaseType::terminate_command();
        std::cout << std::endl; // TODO : otherwise nothing gets printed...
    }
}


#endif	/* AL5D_CPP_CONSOLETRAIT_TPP */
