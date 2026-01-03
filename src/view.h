#pragma once

#include <string>
#include <vector>

class View {
   public:
    std::string el_to_line(int a);
    std::string arr_to_line(std::vector<int> Array);
    std::string get_variants();
    std::string get_error();
    std::string get_arr_req();
    std::string get_arr_len();
    std::string get_el_req();
    std::string get_el_id();
    std::string get_missing_msg();
    std::string get_msg_ending(int n);
};
