// HEADER INCLUDE
#include <al5d_cpp/exceptions.hpp>

#define INVALID_BOARD_CHANNEL "Invalid board channel given: "
#define INVALID_DEGREE "Invalid degree given"
#define INVALID_DEGREE_RANGE "Invalid DegreeRange"
#define INVALID_POSE_NAME "Invalid pose name given: "
#define INVALID_PULSE_WIDTH "Invalid pulse width in config"
#define INVALID_PULSE_WIDTH_RANGE "Invalid pulse_width_range in config"
#define MISSING_COMMUNICATOR "communicator_ptr is nullptr. Use a trait like SerialTrait to set its value."
#define DEGREES_OUT_OF_RANGE "degree out of range: "
#define INVALID_JOINT_TYPE "invalid joint type"
#define INVALID_JOINT_NAME "invalid joint name"


namespace al5d_cpp
{
    InvalidBoardChannel::InvalidBoardChannel(
        const BoardChannel& board_channel)
        : runtime_error(std::string(INVALID_BOARD_CHANNEL) + std::to_string(board_channel))
    {
    }


    InvalidDegree::InvalidDegree()
        : runtime_error(INVALID_DEGREE)
    {
    }


    InvalidDegreeRange::InvalidDegreeRange()
        : runtime_error(INVALID_DEGREE_RANGE)
    {
    }


    InvalidNumberOfJoints::InvalidNumberOfJoints(
        int number_of_given_joints)
        : runtime_error(std::string("Expected '6' joints but got '") + std::to_string(number_of_given_joints) + "'") // TODO : shrink line size
    {
    }


    InvalidPoseName::InvalidPoseName(
        const std::string& pose_name)
        : runtime_error(std::string(INVALID_POSE_NAME) + pose_name)
    {
    }


    InvalidPulseWidth::InvalidPulseWidth()
        : runtime_error(INVALID_PULSE_WIDTH)
    {
    }


    InvalidPulseWidthRange::InvalidPulseWidthRange()
        : runtime_error(INVALID_PULSE_WIDTH_RANGE)
    {
    }


    MissingCommunicator::MissingCommunicator()
        : runtime_error(MISSING_COMMUNICATOR)
    {
    }


    DegreeOutOfRange::DegreeOutOfRange(
        const Degree& degree)
        : runtime_error(std::string(DEGREES_OUT_OF_RANGE) + std::to_string(degree.value))
    {
    }


    InvalidJointType::InvalidJointType()
        : runtime_error(INVALID_JOINT_TYPE)
    {
    }


    InvalidJointName::InvalidJointName()
        : runtime_error(INVALID_JOINT_NAME)
    {
    }
}
