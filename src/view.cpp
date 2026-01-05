#include "view.h"

    std::string View::note_to_line(std::vector<std::string> note){
        std::string line = "";
        for(int i = 0; i < note.size(); i++){
            line += note[i] + " ";
        }

        return line;
    }

    std::string View::note_list_to_line(std::vector<std::vector<std::string>> note_list){
        std::string line;
        for(int i = 0; i < note_list.size(); i++){
            line += note_to_line(note_list[i]) + "\n";
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
        "0. Exit\n"
        "Select a task (0-3): ";
    return variants;
}

std::string View::get_note_name_req() {
    std::string line = "Enter note name:\n> ";
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
