#ifndef AL5D_CPP_LAMBDAROBOT_HPP
#define AL5D_CPP_LAMBDAROBOT_HPP

// SYSTEM INCLUDES
#include <functional>
#include <string>


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
    class LambdaRobot : public BaseType
    {
    public:
        typedef LambdaRobotConfig<BaseType> Config;

        explicit LambdaRobot(
            const Config& config);

        virtual ~LambdaRobot() = default;
    
    protected:

        void transmit( // overrides ICommunicator
            const std::string& message)
            override;

    private:

        OnTransmitFn on_trasmit_fn;
    };
}


#include "LambdaRobot.tpp"

#endif // AL5D_CPP_LAMBDAROBOT_HPP
