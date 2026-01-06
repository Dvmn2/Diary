#include "view.h"

std::vector<std::string> View::note_list_list_to_note_list(
    const std::vector<std::vector<std::string>>& note_list) {
    std::vector<std::string> result;
    result.reserve(note_list.size());

    for (const auto& note : note_list) {
        result.push_back(note_list_to_line(note));
    }
    return result;
}

std::string View::note_list_to_line(const std::vector<std::string>& note) {
    constexpr int max_len = 20;
    std::ostringstream out;

    for (const auto& part_raw : note) {
        std::string part = part_raw;

        part.erase(std::remove(part.begin(), part.end(), '\n'), part.end());
        part.erase(std::remove(part.begin(), part.end(), '\r'), part.end());

        if (part.size() > max_len)
            part = part.substr(0, max_len - 3) + "...";
        else
            part.append(max_len - part.size(), ' ');

        out << part << "     ";
    }

    return out.str();
}

std::string View::note_list_list_to_line(
    const std::vector<std::vector<std::string>>& note_list) {
    std::ostringstream out;
    for (const auto& note : note_list) {
        out << note_list_to_line(note) << "\n";
    }
    return out.str();
}

std::string View::get_self_variants(const std::vector<std::string>& array) {
    std::ostringstream out;

    for (size_t i = 0; i < array.size(); ++i) {
        out << (i + 1) << ". " << array[i] << "\n";
    }

    out << "0. Exit\n"
        << "Select a task (0-" << array.size() << "): ";

    return out.str();
}
