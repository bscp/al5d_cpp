#ifndef AL5D_CPP_SERIALTRAIT_HPP
#define	AL5D_CPP_SERIALTRAIT_HPP

// SYSTEM INCLUDES
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/Serial.hpp>
#include <al5d_cpp/base/configs/AL5DBaseConfig.hpp>


namespace al5d_cpp
{
    template <typename BaseType>
    class SerialTrait : public BaseType
    {
    public:

        explicit SerialTrait(
            const AL5DBaseConfig& config);
        
        virtual ~SerialTrait();
        
    private:
            
        void connect();

        void log_connecting()
            const;
        
        serial::Port serial_port;
        serial::BaudRate serial_baud_rate;
    };
}


#include "SerialTrait.tpp"

#endif	/* AL5D_CPP_SERIALTRAIT_HPP */
