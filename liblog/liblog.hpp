#pragma once

#include <string>

enum class loglevel_t
{
    error = 1,
    warnings = 2,
    everything = 3
};

class logger
{
public:
    logger(loglevel_t loglevel);
    ~logger();

    bool log_error(std::string error_str);
    bool log_warning(std::string warning_str);
    bool log(std::string log_str);

private:
    loglevel_t m_loglevel;
};

using logger_t = logger;