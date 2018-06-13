#include "liblog.hpp"

#include <iostream>
#include <string>

logger::logger(loglevel_t loglevel)
{
    m_loglevel = loglevel;
}

logger::~logger()
{
    #warning TODO: make destructor flush log to file
}

bool logger::log_error(std::string error_str)
{
    if (m_loglevel >= loglevel_t::error)
    {
        std::cout << "[ERROR] " << error_str << std::endl;
    }
    
    return false;
}

bool logger::log_warning(std::string warning_str)
{
    if (m_loglevel >= loglevel_t::warnings)
    {
        std::cout << "[WARNING] " << warning_str << std::endl;
        return true;
    }

    return false;
}

bool logger::log(std::string log_str)
{
    if (m_loglevel >= loglevel_t::everything)
    {
        std::cout << "[LOG] " << log_str << std::endl;
        return true;
    }

    return false;
}