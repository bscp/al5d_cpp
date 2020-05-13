#ifndef AL5D_CPP_CONSOLETRAIT_HPP
#define	AL5D_CPP_CONSOLETRAIT_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>


namespace al5d
{
    template <typename BaseType>
    class ConsoleTrait : public BaseType
    {
    public:
        explicit ConsoleTrait(
            const AL5DBaseConfig& config);

        void terminate_command()
            const
            override;
    };
}


#include "ConsoleTrait.tpp"

#endif	/* AL5D_CPP_CONSOLETRAIT_HPP */
