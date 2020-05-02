#ifndef AL5D_CPP_LAMBDAROBOT_TPP
#define	AL5D_CPP_LAMBDAROBOT_TPP


namespace al5d
{
    template <typename BaseType>
    LambdaRobot<BaseType>::LambdaRobot(
        const Config& config)
        : BaseType(config)
        , on_trasmit_fn(config.on_transmit_fn)
    {
    }


    template <typename BaseType>
    void LambdaRobot<BaseType>::transmit(
        const std::string& message)
    {
        on_trasmit_fn(message);
    }
}


#endif	/* AL5D_CPP_LAMBDAROBOT_TPP */
