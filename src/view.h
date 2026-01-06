#pragma once

#include <string>
#include <vector>

class View {
   public:
    std::vector<std::string> note_list_list_to_note_list(
        std::vector<std::vector<std::string>> note_list);
    std::string note_list_to_line(std::vector<std::string> note);
    std::string note_list_list_to_line(std::vector<std::vector<std::string>> note_list);

    std::string get_self_variants(std::vector<std::string> Array);

    std::string get_db_variants();
    std::string get_db_name_req();
    std::string get_db_absent();

    std::string get_table_variants();
    std::string get_table_name_req();

    std::string get_note_variants();
    std::string get_note_name_req();

    std::string get_int_req();
    std::string get_el_req();
    std::string get_el_id_req();
    std::string get_text_req();
    std::string get_keywords_req();
    std::string get_already_exists();
    std::string get_error();
    std::string get_success();
    std::string get_missing_msg();
    std::string get_space(int n);
};
