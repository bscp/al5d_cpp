#ifndef AL5D_CPP_LOGGING_HPP
#define AL5D_CPP_LOGGING_HPP

// SYSTEM INCLUDES
#include <string>


namespace al5d_cpp
{
    void log_info(const std::string &line);
    void log_debug(const std::string &line);
    void log_warning(const std::string &line);
    void log_error(const std::string &line);
}


#define LOG_INFO al5d_cpp::log_info
#define LOG_DEBUG al5d_cpp::log_debug
#define LOG_WARNING al5d_cpp::log_warning
#define LOG_ERROR al5d_cpp::log_error

#endif // AL5D_CPP_LOGGING_HPP
