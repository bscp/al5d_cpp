
#ifndef AL5D_CPP_AL5D6D_HPP
#define AL5D_CPP_AL5D6D_HPP

// SYSTEM INCLUDES
#include <map>
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/AL5D.hpp>
#include <al5d_cpp/AL5D6DConfig.hpp>
#include <al5d_cpp/types.hpp>

namespace al5d
{
    enum AL5D6DJointType
    {
        JOINT_BASE,
        JOINT_SHOULDER,
        JOINT_ELBOW,
        JOINT_WRIST,
        JOINT_GRIPPER,
        JOINT_WRIST_ROTATE,
    };

    class AL5D6D : public AL5D
    {
    public:
        typedef std::map<AL5D6DJointType, PulseWidth> JointPulseWidthMap;
        typedef std::map<AL5D6DJointType, AL5D6DJointType> JointTypeMap;
    
        explicit AL5D6D(const SerialPort &serial_port, const AL5D6DConfig &config = AL5D6DConfig());
        
        virtual ~AL5D6D() = default;
    
        void close_gripper();
        
        void open_gripper();

    protected:
        explicit AL5D6D(CommunicatorPtr communicator_ptr, const AL5D6DConfig &config=AL5D6DConfig());
        
    private:
        AL5D::JointMap create_joint_map(const AL5D6DConfig &config) const;
    };
}

#endif // AL5D_CPP_AL5D6D_HPP
