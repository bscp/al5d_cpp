#ifndef AL5D_CPP_CONSOLETRAIT_HPP
#define	AL5D_CPP_CONSOLETRAIT_HPP

// PROJECT INCLUDES
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>
#include <al5d_cpp/settings.hpp>


namespace al5d_cpp
{
    template <typename BaseType>
    class ConsoleTrait : public BaseType
    {
    public:
        explicit ConsoleTrait(
            const AL5DBaseConfig& config=
                al5d_cpp::al5d_config_from_json_file(DEFAULT_AL5D_JSON_FILE_PATH));

        void transmit_command_terminator_()
            const
            override;
    };
}


#include "ConsoleTrait.tpp"

#endif	/* AL5D_CPP_CONSOLETRAIT_HPP */
