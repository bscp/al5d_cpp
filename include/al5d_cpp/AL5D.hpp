
#ifndef AL5D_CPP_AL5D_HPP
#define AL5D_CPP_AL5D_HPP

// SYSTEM INCLUDES
#include <cstdint>
#include <map>

// PROJECT INCLUDES
#include <al5d_cpp/Communicator.hpp>
#include <al5d_cpp/Joint.hpp>
#include <al5d_cpp/communicators/SerialCommunicator.hpp>

namespace al5d
{
    class AL5D
    {
    protected:
        using JointId = uint16_t;
        using JointMap = std::map<JointId, Joint>;
        
    public:
        using JointPulseWidthMap = std::map<JointId, PulseWidth>;
        using JointDegreesMap = std::map<JointId, Degrees>;
        
    public:
        virtual ~AL5D() = default;
    
        void move_to_pulse_widths(const JointPulseWidthMap &joint_pulse_widths) const;
        
        void move_to_degrees(const JointDegreesMap &join_degrees) const;

        void stop() const;

    protected:
        explicit AL5D(CommunicatorPtr communicator_ptr, JointMap joints=JointMap());
        
        void transmit(const Command &command) const;
    
        const Joint &get_joint(const JointId &joint_type) const;
        
    private:
        CommunicatorPtr communicator_ptr;
        JointMap joints;
    };
}

#endif // AL5D_CPP_AL5D_HPP
