#ifndef AL5D_CPP_LAMBDATRAIT_HPP
#define AL5D_CPP_LAMBDATRAIT_HPP

// SYSTEM INCLUDES
#include <functional>
#include <string>


namespace al5d
{
    typedef std::function<void(const std::string&)> OnTransmitFn;


    template <typename BaseType>
    class LambdaTraitConfig : public BaseType::Config
    {
    public:
        OnTransmitFn on_transmit_fn;
    };


    template <typename BaseType>
    class LambdaTrait : public BaseType
    {
    public:
        typedef LambdaTraitConfig<BaseType> Config;

        explicit LambdaTrait(
            const Config& config);

        virtual ~LambdaTrait() = default;
            
        void connect()
            override;
        
        bool is_connected() 
            override;
        
        void disconnect()
            override;
    
    protected:

        void transmit( 
            const std::string& message)
            override;

    private:

        OnTransmitFn on_trasmit_fn;
    };
}


#include "LambdaTrait.tpp"

#endif // AL5D_CPP_LAMBDATRAIT_HPP
