#ifndef AL5D_CPP_CONSOLETRAIT_HPP
#define	AL5D_CPP_CONSOLETRAIT_HPP

// SYSTEM INCLUDES
#include <string>


namespace al5d
{
    template <typename BaseType>
    class ConsoleTrait : public BaseType
    {
    public:
        typedef typename BaseType::Config Config;
       
        explicit ConsoleTrait(
            const Config &config);

        void terminate_command()
            const
            override;
    };
}


#include "ConsoleTrait.tpp"

#endif	/* AL5D_CPP_CONSOLETRAIT_HPP */
