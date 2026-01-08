#include "view.h"

std::vector<std::string> View::notes_to_lines(const std::vector<note>& note_list) {
    std::vector<std::string> result;
    for (const auto& rec : note_list) {
        result.push_back(note_to_line(rec));
    }
    return result;
}

std::string View::note_to_line(const note& rec) {
    int max_len = 20;
    std::ostringstream out;  // cout только в переменную и с переводом в коде

    std::string text = rec.text;
    std::replace(text.begin(), text.end(), '\n', ' ');  // Заменяем ненужное
    std::replace(text.begin(), text.end(), '\r', ' ');
    if (text.size() > max_len) {  // Форматируем
        text = text.substr(0, max_len - 3) + "...";
    } else {
        text.append(max_len - text.size(), ' ');
    }

    std::string keywords = rec.keywords;
    std::replace(keywords.begin(), keywords.end(), '\n', ' ');
    std::replace(keywords.begin(), keywords.end(), '\r', ' ');
    if (keywords.size() > max_len) {
        keywords = keywords.substr(0, max_len - 3) + "...";
    } else {
        keywords.append(max_len - keywords.size(), ' ');
    }

    out << text << "     " << keywords << "     " << rec.time;
    return out.str();
}

std::string View::notes_to_line(const std::vector<note>& note_list) {
    std::ostringstream out;
    for (const auto& rec : note_list) {
        out << note_to_line(rec) << "\n";
    }
    return out.str();
}

std::string View::full_note(const note& rec) {
    std::ostringstream out;
    out << rec.text << "\n" << rec.keywords << "\n" << rec.time << "\n";
    return out.str();
}

std::string View::join_variants(const std::vector<std::string>& array) {
    std::ostringstream out;
    for (size_t i = 0; i < array.size(); ++i) {
        out << (i + 1) << ". " << array[i] << "\n";
    }
    out << "0. Exit\n"
        << "Select a task (0-" << array.size() << "): ";
    return out.str();
}
