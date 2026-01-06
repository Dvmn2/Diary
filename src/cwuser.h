#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <limits>

class CWUser {
public:
    std::string inp_line() const;
    std::string inp_text() const;
    std::string inp_word() const;

    void out_line(const std::string& line) const;
};
