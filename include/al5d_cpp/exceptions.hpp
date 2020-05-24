#ifndef AL5D_CPP_EXCEPTIONS_HPP
#define AL5D_CPP_EXCEPTIONS_HPP

// SYSTEM INCLUDES
#include <stdexcept>
#include <string>

// PROJECT INCLUDES
#include <al5d_cpp/base/types.hpp>


namespace al5d_cpp
{
    class InvalidBoardChannel : public std::runtime_error
    {
    public:
        explicit InvalidBoardChannel(
            const BoardChannel& board_channel);
    };


    class InvalidDegree : public std::runtime_error
    {
    public:
        explicit InvalidDegree();
    };


    class InvalidDegreeRange : public std::runtime_error
    {
    public:
        InvalidDegreeRange();
    };


    class InvalidNumberOfJoints : public std::runtime_error
    {
    public:
        explicit InvalidNumberOfJoints(
            int number_of_given_joints);
    };


    class InvalidPoseName : public std::runtime_error
    {
    public:
        explicit InvalidPoseName(
            const std::string& pose_name);
    };


    class InvalidPulseWidth : public std::runtime_error
    {
    public:
        InvalidPulseWidth();
    };


    class InvalidPulseWidthRange : public std::runtime_error
    {
    public:
        InvalidPulseWidthRange();
    };

    
    class MissingCommunicator : public std::runtime_error
    {
    public:
        MissingCommunicator();
    };

    
    class DegreeOutOfRange : public std::runtime_error
    {
    public:
        explicit DegreeOutOfRange(
            const Degree& degree);
    };

    class InvalidJointType : public std::runtime_error
    {
    public:
        InvalidJointType();
    };

    class InvalidJointName : public std::runtime_error
    {
    public:
        InvalidJointName();
    };
}


#endif // AL5D_CPP_EXCEPTIONS_HPP
