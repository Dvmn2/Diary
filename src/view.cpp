#include "view.h"

std::vector<std::string> View::note_list_list_to_note_list(
    std::vector<std::vector<std::string>> note_list) {
    std::vector<std::string> line = {};
    for (int i = 0; i < note_list.size(); i++) {
        line.push_back(note_list_to_line(note_list[i]));
    }

    return line;
}

std::string View::note_list_to_line(std::vector<std::string> note) {
    std::string line = "";
    int max_len = 20;
    for (int i = 0; i < note.size(); i++) {
        std::string part = note[i];
        part.erase(std::remove(part.begin(), part.end(), '\n'), part.end());
        part.erase(std::remove(part.begin(), part.end(), '\r'), part.end());
        if (part.length() > max_len) {
            part = part.substr(0, max_len - 3) + "...";
        }
        if (part.length() < max_len) {
            part += std::string(max_len - part.length(), ' ');
        }
        line += part + "     ";
    }

    return line;
}

std::string View::note_list_list_to_line(
    std::vector<std::vector<std::string>> note_list) {
    std::string line;
    for (int i = 0; i < note_list.size(); i++) {
        line += note_list_to_line(note_list[i]) + "\n";
    }

    return line;
}

std::string View::get_self_variants(std::vector<std::string> Array) {
    std::string variants = "";
    int i;
    for (i = 1; i <= Array.size(); i++) {
        variants += std::to_string(i) + ". " + Array[i - 1] + "\n";
    }
    variants +=
        "0. Exit\n"
        "Select a task (0-" +
        std::to_string(i - 1) + "): ";

    return variants;
}

std::string View::get_db_variants() {
    std::string variants =
        "1. Select database\n"
        "2. Create database\n"
        "3. Delete database\n"
        "0. Exit\n"
        "Select a task (0-3): ";
    return variants;
}

std::string View::get_db_name_req() {
    std::string line = "Enter database name:\n> ";
    return line;
}

std::string View::get_db_absent() {
    std::string line = "First, create a database\n";
    return line;
}

std::string View::get_table_variants() {
    std::string variants =
        "1. Select table\n"
        "2. Create table\n"
        "3. Delete table\n"
        "0. Exit\n"
        "Select a task (0-3): ";
    return variants;
}

std::string View::get_table_name_req() {
    std::string line = "Enter table name:\n> ";
    return line;
}

std::string View::get_note_variants() {
    std::string variants =
        "1. Find note\n"
        "2. Create note\n"
        "3. Delete note\n"
        "4. Edit note\n"
        "5. Read note\n"
        "0. Exit\n"
        "Select a task (0-5): ";
    return variants;
}

std::string View::get_note_name_req() {
    std::string line = "Enter note name:\n> ";
    return line;
}

std::string View::get_int_req() {
    std::string line = "Enter integer number:\n> ";
    return line;
}

std::string View::get_el_id_req() {
    std::string line = "Enter element number:\n> ";
    return line;
}

std::string View::get_el_req() {
    std::string line = "Enter element:\n> ";
    return line;
}

std::string View::get_already_exists() {
    std::string line = "This name already exists\n";
    return line;
}

std::string View::get_text_req() {
    std::string line = "Enter text (0 - Finish):\n";
    return line;
}

std::string View::get_keywords_req() {
    std::string line = "Enter keywords (0 - Finish):\n";
    return line;
}

std::string View::get_search_req() {
    std::string line = "Enter keyword:\n> ";
    return line;
}

std::string View::get_note_id_req() {
    std::string line = "Enter note id:\n> ";
    return line;
}

std::string View::get_error() {
    std::string line = "Something went wrong\n";
    return line;
}

std::string View::get_success() {
    std::string line = "Successful\n";
    return line;
}

std::string View::get_missing_msg() {
    std::string line = "Non-existent task\n";
    return line;
}

std::string View::get_space(int n) {
    std::string line = "";
    for (int i = 0; i < n; i++) {
        line += "\n";
    }
    return line;
}
