#pragma once

#include <fstream>
#include <string>
#include <vector>

enum class loglevel_t
{
    errors = 1,
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

    bool dump_log(std::string file);

private:
    std::vector<std::string> log_history;
    loglevel_t m_loglevel;
};

using logger_t = logger;
using loglevel = loglevel_t;