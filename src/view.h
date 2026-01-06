#pragma once

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

class View {
   public:
    std::vector<std::string> flatten_note_list(
        const std::vector<std::vector<std::string>>& notes);

    std::string note_to_line(const std::vector<std::string>& note);
    std::string notes_to_line(const std::vector<std::vector<std::string>>& notes);

    std::string join_variants(const std::vector<std::string>& items);

    static constexpr const char* DB_MENU =
        "1. Select database\n"
        "2. Create database\n"
        "3. Delete database\n"
        "0. Exit\n"
        "Select a task (0-3): ";

    static constexpr const char* DB_NAME_PROMPT = "Enter database name:\n> ";

    static constexpr const char* DB_NOT_SELECTED = "First, create a database\n";

    static constexpr const char* TABLE_MENU =
        "1. Select table\n"
        "2. Create table\n"
        "3. Delete table\n"
        "0. Exit\n"
        "Select a task (0-3): ";

    static constexpr const char* TABLE_NAME_PROMPT = "Enter table name:\n> ";

    static constexpr const char* NOTE_MENU =
        "1. Find note\n"
        "2. Create note\n"
        "3. Delete note\n"
        "4. Edit note\n"
        "5. Read note\n"
        "0. Exit\n"
        "Select a task (0-5): ";

    static constexpr const char* NOTE_NAME_PROMPT = "Enter note name:\n> ";

    static constexpr const char* INT_PROMPT = "Enter integer number:\n> ";

    static constexpr const char* ELEMENT_PROMPT = "Enter element:\n> ";

    static constexpr const char* ELEMENT_ID_PROMPT = "Enter element number:\n> ";

    static constexpr const char* TEXT_PROMPT = "Enter text (0 - Finish):\n";

    static constexpr const char* KEYWORDS_PROMPT = "Enter keywords (0 - Finish):\n";

    static constexpr const char* SEARCH_PROMPT = "Enter keyword:\n> ";

    static constexpr const char* NOTE_ID_PROMPT = "Enter note id:\n> ";

    static constexpr const char* NAME_ALREADY_EXISTS = "This name already exists\n";

    static constexpr const char* ERROR_MSG = "Something went wrong\n";

    static constexpr const char* SUCCESS_MSG = "Successful\n";

    static constexpr const char* INVALID_OPTION_MSG = "Non-existent task\n";

    static std::string repeat_new_lines(int count) { return std::string(count, '\n'); }

    /*
    static
    Метод принадлежит классу, а не объекту
    Его можно вызвать без создания экземпляра:
    MyClass::get_already_exists();

    constexpr
    Гарантирует, что функция может быть вычислена на этапе компиляции, если это
    возможно.

    const char*
    Возвращаемый тип — указатель на константную C‑строку.
    */
};