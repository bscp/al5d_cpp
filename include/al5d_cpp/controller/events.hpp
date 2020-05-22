#ifndef AL5D_CPP_EVENTS_HPP
#define AL5D_CPP_EVENTS_HPP


namespace al5d_cpp
{
    enum EventType
    {
        EVENT_MOVING_FINISHED,
        EVENT_NEW_COMMAND_PLANNED,
        UNHALT_COMMAND_RECEIVED,
        EVENT_CONNECTING_FINISHED,
        EVENT_INITIALIZING_FINISHED,
        EVENT_FINALIZING_FINISHED,
        EVENT_SHUTDOWN_REQUESTED,
        EVENT_CALIBRATING_FINISHED,
    };
}


#endif // AL5D_CPP_EVENTS_HPP
