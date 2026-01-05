#pragma once

#include <iostream>
#include <vector>
#include <string>

class CWUser {
   public:
    std::string inp_line();
    std::vector<int> inp_array(int n);
    std::string inp_word();
    void out_line(std::string line);
};
