#pragma once

#include <iostream>
#include <vector>

class CWUser {
   public:
    std::string inp_line();
    std::vector<int> inp_array(int n);
    void output(std::string line);
};
