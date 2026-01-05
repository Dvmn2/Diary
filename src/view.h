#pragma once

#include <string>
#include <vector>

class View {
   public:
    std::string el_to_line(int a);
    std::string arr_to_line(std::vector<int> Array);
    std::string db_to_line();

    std::string get_self_variants(std::vector<std::string> Array);

    std::string get_db_variants();
    std::string get_db_name_req();
    std::string get_db_absent();

    std::string get_table_variants();
    std::string get_table_name_req();

    std::string get_rec_variants();
    std::string get_rec_name_req();

    std::string get_el_req();
    std::string get_el_id_req();
    std::string get_already_exists();
    std::string get_error();
    std::string get_success();
    std::string get_missing_msg();
    std::string get_space(int n);
};
