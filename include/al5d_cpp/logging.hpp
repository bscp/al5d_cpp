
#ifndef AL5D_CPP_LOGGING_HPP
#define AL5D_CPP_LOGGING_HPP

#include <string>

namespace al5d
{
    void log_info(const std::string &line);
    void log_debug(const std::string &line);
    void log_error(const std::string &line);
}

#define LOG_INFO log_info
#define LOG_DEBUG log_debug
#define LOG_ERROR log_debug

#endif // AL5D_CPP_LOGGING_HPP
