// CCalc, one stop shop for mathematical formulas
// Copyright (C) 2018 Chronix
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>

#define BLANK_STR ""

enum loglevel_t
{
    print = 0,
    errors = 1,
    warnings = 2,
    everything = 3
};

class logger
{
public:
    logger(loglevel_t loglevel, std::string logfile);
    logger(loglevel_t loglevel);

    // use defaults (which are to log everything and set filename to logger.log)
    logger();

    // when object is deconstructed, all log history is flushed from the vector into a log file
    ~logger();

    // logging functions
    bool log_error(std::string error_str);
    bool log_warning(std::string warning_str);
    bool log(std::string log_str);

    bool log_value(std::string log_str, int value);
	bool log_value(std::string log_str, float value);
    bool log_value(std::string log_str, double value);

	bool log_value(int value);
	bool log_value(float value);
	bool log_value(double value);

    // print function - goes into log_history to be flushed unlike std::cout
    bool print(std::string print_str);
    bool just_print(std::string print_str);

    // called by deconstructor, but can also be called manually
    bool dump_log(std::string file);
	bool dump_log();

private:
    std::vector<std::string> log_history;
    std::string m_logfile;
    loglevel_t m_loglevel;
};

using logger_t = logger;
