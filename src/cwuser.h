#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <limits>

class CWUser {
public:
    std::string inp_line();
    std::string inp_text();
    std::string inp_word();

    void out_line(const std::string& line);
};
