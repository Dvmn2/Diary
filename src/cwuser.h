#pragma once

#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include <vector>

class CWUser {
   public:
    std::string CWUser::db_filter(const std::string& input);
    std::string inp_line();
    std::string inp_text();
    std::string inp_word();

    void out_line(const std::string& line);
};
