#ifndef AL5D_CPP_LAMBDATRAIT_TPP
#define	AL5D_CPP_LAMBDATRAIT_TPP


namespace al5d_cpp
{
    template <typename BaseType>
    LambdaTrait<BaseType>::LambdaTrait(
        const AL5DBaseConfig& config)
        : BaseType(config)
    {
        auto ptr = LambdaCommunicator::as_pointer();
        BaseType::set_communicator_ptr(ptr);
    }


    template <typename BaseType>
    void LambdaTrait<BaseType>::set_transmit_fn(
        const TransmitFn& transmit_fn)
    {
        auto ptr = std::dynamic_pointer_cast<LambdaCommunicator>(BaseType::communicator_ptr_);
        ptr->set_transmit_fn(transmit_fn);
    }
}


#endif	/* AL5D_CPP_LAMBDATRAIT_TPP */
