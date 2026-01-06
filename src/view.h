#pragma once

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

class View {
   public:
    std::vector<std::string> note_list_list_to_note_list(
        const std::vector<std::vector<std::string>>& note_list);

    std::string note_list_to_line(const std::vector<std::string>& note);
    std::string note_list_list_to_line(
        const std::vector<std::vector<std::string>>& note_list);

    std::string get_self_variants(const std::vector<std::string>& array);

    static constexpr const char* get_db_variants() {
        return "1. Select database\n"
               "2. Create database\n"
               "3. Delete database\n"
               "0. Exit\n"
               "Select a task (0-3): ";
    }

    static constexpr const char* get_db_name_req() {
        return "Enter database name:\n> ";
    }
    static constexpr const char* get_db_absent() {
        return "First, create a database\n";
    }

    static constexpr const char* get_table_variants() {
        return "1. Select table\n"
               "2. Create table\n"
               "3. Delete table\n"
               "0. Exit\n"
               "Select a task (0-3): ";
    }

    static constexpr const char* get_table_name_req() {
        return "Enter table name:\n> ";
    }

    static constexpr const char* get_note_variants() {
        return "1. Find note\n"
               "2. Create note\n"
               "3. Delete note\n"
               "4. Edit note\n"
               "5. Read note\n"
               "0. Exit\n"
               "Select a task (0-5): ";
    }

    static constexpr const char* get_note_name_req() { return "Enter note name:\n> "; }
    static constexpr const char* get_int_req() { return "Enter integer number:\n> "; }
    static constexpr const char* get_el_req() { return "Enter element:\n> "; }
    static constexpr const char* get_el_id_req() { return "Enter element number:\n> "; }
    static constexpr const char* get_text_req() { return "Enter text (0 - Finish):\n"; }
    static constexpr const char* get_keywords_req() {
        return "Enter keywords (0 - Finish):\n";
    }
    static constexpr const char* get_search_req() { return "Enter keyword:\n> "; }
    static constexpr const char* get_note_id_req() { return "Enter note id:\n> "; }

    static constexpr const char* get_already_exists() {
        return "This name already exists\n";
    }
    static constexpr const char* get_error() { return "Something went wrong\n"; }
    static constexpr const char* get_success() { return "Successful\n"; }
    static constexpr const char* get_missing_msg() { return "Non-existent task\n"; }

    static std::string get_space(int n) { return std::string(n, '\n'); }
};
