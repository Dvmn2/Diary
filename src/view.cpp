#include "view.h"

std::string View::el_to_line(int a) { return std::to_string(a); }

std::string View::arr_to_line(std::vector<int> Array) {
    std::string line = "";
    for (int i = 0; i < Array.size(); i++) {
        line += el_to_line(Array[i]) + " ";
    }
    return line;
}

std::string View::get_variants() {
    std::string variants =
        "1. Add data\n"
        "2. Add element\n"
        "3. Get data\n"
        "4. Get element\n"
        "0. Exit\n"
        "Select a task (0-4): ";
    return variants;
}

std::string View::get_error() {
    std::string line = "Something went wrong\n";
    return line;
}

std::string View::get_arr_req() {
    std::string line = "Enter data:\n> ";
    return line;
}

std::string View::get_arr_len() {
    std::string line = "Enter data length:\n> ";
    return line;
}

std::string View::get_el_id() {
    std::string line = "Enter element number:\n> ";
    return line;
}

std::string View::get_el_req() {
    std::string line = "Enter element:\n> ";
    return line;
}

std::string View::get_missing_msg() {
    std::string line = "Non-existent task\n";
    return line;
}

std::string View::get_msg_ending(int n) {
    std::string line = "";
    for (int i = 0; i < n; i++) {
        line += "\n";
    }
    return line;
}
