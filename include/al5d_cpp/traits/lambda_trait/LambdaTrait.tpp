#ifndef AL5D_CPP_LAMBDATRAIT_TPP
#define	AL5D_CPP_LAMBDATRAIT_TPP


namespace al5d
{
    template <typename BaseType>
    LambdaTrait<BaseType>::LambdaTrait(
        const Config& config)
        : BaseType(config)
        , on_trasmit_fn(config.on_transmit_fn)
    {
    }


    template <typename BaseType>
    void LambdaTrait<BaseType>::transmit(
        const std::string& message)
    {
        on_trasmit_fn(message);
    }
    
    
    template <typename BaseType>
    void LambdaTrait<BaseType>::connect()
    {
        // TODO : implement   
    }


    template <typename BaseType>
    bool LambdaTrait<BaseType>::is_connected()
    {
        return true; // TODO : implement
    }
    

    template <typename BaseType>
    void LambdaTrait<BaseType>::disconnect()
    {
        // TODO : implement
    }
}


#endif	/* AL5D_CPP_LAMBDATRAIT_TPP */
