#ifndef AL5D_CPP_LAMBDAROBOT_HPP
#define AL5D_CPP_LAMBDAROBOT_HPP

// SYSTEM INCLUDES
#include <functional>
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/interfaces/ICommunicator.hpp>


namespace al5d
{
    typedef std::function<void(const std::string&)> OnTransmitFn;


    template <typename BaseType>
    class LambdaRobotConfig : public BaseType::Config
    {
    public:
        OnTransmitFn on_transmit_fn;
    };


    template <typename BaseType>
    class LambdaRobot : public BaseType, ICommunicator
    {
    public:
        typedef LambdaRobotConfig<BaseType> Config;

        LambdaRobot(
            const Config& config)
            : BaseType(config)
            , on_trasmit_fn(config.on_transmit_fn)
        {
        }

        virtual ~LambdaRobot() = default;
    
    protected:
        void transmit( // overrides ICommunicator
            const std::string& message)
            final
        {
            on_trasmit_fn(message);
        }

    private:
        OnTransmitFn on_trasmit_fn;
    };
}


#endif // AL5D_CPP_LAMBDAROBOT_HPP
