// HEADER INCLUDE
#include <al5d_cpp/logging.hpp>

// SYSTEM INCLUDES
#include <iostream>


namespace al5d_cpp
{
    void log_trace(const std::string &line)
    {
        std::cout << "TRACE :: " << line << "\n";
    }


    void log_info(const std::string &line)
    {
        std::cout << "INFO :: " << line << "\n";
    }
    
    
    void log_debug(const std::string &line)
    {
        std::cout << "DEBUG :: " << line << "\n";
    }
    
    
    void log_warning(const std::string &line)
    {
        std::cout << "WARNING :: " << line << "\n";
    }
    
    
    void log_error(const std::string &line)
    {
        std::cout << "ERROR :: " << line << "\n";
    }
}
