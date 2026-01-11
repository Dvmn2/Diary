#include "controller.h"

Controller::Controller(CWUser& cwu, View& v, Model& m)
    : cwuser(cwu), view(v), model(m) {}

void Controller::run() { db_work(); }

void Controller::db_work() {  // Database menu
    std::string variants = view.DB_MENU;
    cwuser.out_line(variants);
    int task = int_enter();
    while (task != 0) {
        switch (task) {
            case 1:
                db_task1();
                break;
            case 2:
                db_task2();
                break;
            case 3:
                db_task3();
                break;
            case 4:
                db_task4();
                break;
            default:
                missing();
                break;
        }
        cwuser.out_line(variants);
        task = int_enter();
    }
}

void Controller::db_task1() {  // Select database
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> db_list = model.database_list();
    std::string variants = view.join_variants(db_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (model.database_connect(id)) {            // Пока не получилось подключиться
        cwuser.out_line(view.repeat_new_lines(1));  // Пытаемся ещё раз
        cwuser.out_line(variants);
        id = int_enter();
    }  // Выход если 0 или получилось
    if (id) {  // Если получилось
        cwuser.out_line(view.repeat_new_lines(1));
        table_work();  // Переходим к таблицам
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::db_task2() {  // Create database
    cwuser.out_line(view.DB_NAME_PROMPT);
    std::string db_name = cwuser.inp_word();
    db_name = cwuser.db_filter(db_name);
    while (model.create_database(db_name)) {        // Пока не получилось создать
        cwuser.out_line(view.NAME_ALREADY_EXISTS);  // Пытаемся ещё раз
        cwuser.out_line(view.DB_NAME_PROMPT);
        db_name = cwuser.inp_word();
    }
    cwuser.out_line(view.SUCCESS_MSG);
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::db_task3() {  // Delete database
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> db_list = model.database_list();
    std::string variants = view.join_variants(db_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (model.delete_database(id)) {             // Пока не получилось удалить
        cwuser.out_line(view.repeat_new_lines(1));  // Пытаемся ещё раз
        cwuser.out_line(variants);
        id = int_enter();
    }  // Выход если 0 или получилось
    if (id) {  // Если получилось
        cwuser.out_line(view.SUCCESS_MSG);
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::db_task4() {  // Rename database
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> db_list = model.database_list();
    std::string variants = view.join_variants(db_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (!model.in_range(id, db_list.size())) {   // Пока id не в диапазоне
        cwuser.out_line(view.repeat_new_lines(1));  // Пытаемся ещё раз
        cwuser.out_line(variants);
        id = int_enter();
    }
    if (id) {  // Если не 0
        cwuser.out_line(view.DB_NAME_PROMPT);
        std::string name = cwuser.inp_word();
        while (model.rename_database(id, name)) {  // Пока не получилось переименновать
            cwuser.out_line(view.DB_NAME_PROMPT);  // Пробуем ещё раз
            name = cwuser.inp_word();
        }
        cwuser.out_line(view.SUCCESS_MSG);
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::table_work() {  // Table menu
    std::string variants = view.TABLE_MENU;
    cwuser.out_line(variants);
    int task = int_enter();
    while (task != 0) {
        switch (task) {
            case 1:
                table_task1();
                break;
            case 2:
                table_task2();
                break;
            case 3:
                table_task3();
                break;
            case 4:
                table_task4();
                break;
            default:
                missing();
                break;
        }
        cwuser.out_line(variants);
        task = int_enter();
    }
}

void Controller::table_task1() {  // Select table
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> table_list = model.table_list();
    std::string variants = view.join_variants(table_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (model.table_connect(id)) {               // Пока не получилось подключиться
        cwuser.out_line(view.repeat_new_lines(1));  // Пытаемся ещё раз
        cwuser.out_line(variants);
        id = int_enter();
    }  // Выход если 0 или получилось
    if (id) {  // Если получилось
        cwuser.out_line(view.repeat_new_lines(1));
        note_work();
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::table_task2() {  // Create table
    cwuser.out_line(view.TABLE_NAME_PROMPT);
    std::string table_name = cwuser.inp_word();
    while (model.create_table(table_name)) {        // Пока не получилось создать
        cwuser.out_line(view.NAME_ALREADY_EXISTS);  // Пытаемся ещё раз
        cwuser.out_line(view.TABLE_NAME_PROMPT);
        table_name = cwuser.inp_word();
    }
    cwuser.out_line(view.SUCCESS_MSG);
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::table_task3() {  // Delete table
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> table_list = model.table_list();
    std::string variants = view.join_variants(table_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (model.delete_table(id)) {                // Пока не получилось удалить
        cwuser.out_line(view.repeat_new_lines(1));  // Пытаемся ещё раз
        cwuser.out_line(variants);
        id = int_enter();
    }  // Выход если 0 или получилось
    if (id) {  // Если получилось
        cwuser.out_line(view.SUCCESS_MSG);
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::table_task4() {  // Rename table
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> db_list = model.table_list();
    std::string variants = view.join_variants(db_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (!model.in_range(id, db_list.size())) {   // Пока id не в диапазоне
        cwuser.out_line(view.repeat_new_lines(1));  // Пытаемся ещё раз
        cwuser.out_line(variants);
        id = int_enter();
    }
    if (id) {  // Если не 0
        cwuser.out_line(view.TABLE_NAME_PROMPT);
        std::string name = cwuser.inp_word();
        while (model.rename_table(id, name)) {  // Пока не получилось переименновать
            cwuser.out_line(view.NAME_ALREADY_EXISTS);  // Пытаемся ещё раз
            cwuser.out_line(view.TABLE_NAME_PROMPT);
            name = cwuser.inp_word();
        }
        cwuser.out_line(view.SUCCESS_MSG);
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::note_work() {  // Note menu
    std::string variants = view.NOTE_MENU;
    cwuser.out_line(variants);
    int task = int_enter();
    while (task != 0) {
        switch (task) {
            case 1:
                note_task1();
                break;
            case 2:
                note_task2();
                break;
            case 3:
                note_task3();
                break;
            case 4:
                note_task4();
                break;
            case 5:
                note_task5();
                break;
            default:
                missing();
                break;
        }
        cwuser.out_line(variants);
        task = int_enter();
    }
}

void Controller::note_task1() {  // Search note
    cwuser.out_line(view.SEARCH_PROMPT);
    std::string search = cwuser.inp_word();
    std::vector<note> note_list = model.search_note(search);
    std::string line = view.notes_to_line(note_list);
    cwuser.out_line(line);
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::note_task2() {  // Create note
    cwuser.out_line(view.TEXT_PROMPT);
    std::string text = cwuser.inp_text();
    cwuser.out_line(view.KEYWORDS_PROMPT);
    std::string keywords = cwuser.inp_text();
    cwuser.out_line(view.repeat_new_lines(1));
    model.create_note(text, keywords);
}

void Controller::note_task3() {  // Delete note
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<note> notes_list = model.notes_list();
    std::vector<std::string> var_list = view.notes_to_lines(notes_list);
    std::string variants = view.join_variants(var_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (model.delete_note(id)) {                 // Пока не получилось удалить
        cwuser.out_line(view.repeat_new_lines(1));  // Пытаемся ещё раз
        cwuser.out_line(variants);
        id = int_enter();
    }
    if (id) {
        cwuser.out_line(view.SUCCESS_MSG);
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::note_task4() {  // Update note
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<note> notes_list = model.notes_list();
    std::vector<std::string> var_list = view.notes_to_lines(notes_list);
    std::string variants = view.join_variants(var_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (!model.in_range(id, var_list.size())) {  // Пока id не в диапазоне
        cwuser.out_line(view.repeat_new_lines(1));  // Пытаемся ещё раз
        cwuser.out_line(variants);
        id = int_enter();
    }
    if (id) {  // Если не 0
        cwuser.out_line(view.TEXT_PROMPT);
        std::string text = cwuser.inp_text();
        cwuser.out_line(view.KEYWORDS_PROMPT);
        std::string keywords = cwuser.inp_text();
        cwuser.out_line(view.repeat_new_lines(1));
        model.update_note(id, text, keywords);
        cwuser.out_line(view.SUCCESS_MSG);
    }

    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::note_task5() {  // Read note
    note rec;
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<note> notes_list = model.notes_list();
    std::vector<std::string> var_list = view.notes_to_lines(notes_list);
    std::string variants = view.join_variants(var_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (!model.in_range(id, var_list.size())) {  // Пока id не в диапазоне
        cwuser.out_line(view.repeat_new_lines(1));  // Пытаемся ещё раз
        cwuser.out_line(variants);
        id = int_enter();
    }
    if (id) {  // Если не 0
        cwuser.out_line(view.repeat_new_lines(1));
        model.read_note(id, rec);
        std::string line = view.full_note(rec);
        cwuser.out_line(line);
    }

    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::missing() {
    cwuser.out_line(view.INVALID_OPTION_MSG);
    cwuser.out_line(view.repeat_new_lines(1));
}

int Controller::int_enter() {
    while (true) {
        try {
            return std::stoi(cwuser.inp_word());
        } catch (...) {
            cwuser.out_line(view.INT_PROMPT);
        }
    }
}

int Controller::select_from_list(const std::vector<std::string>& list) {
    cwuser.out_line(view.join_variants(list));
    int n = int_enter();
    while (n < 0 || n > list.size()) {
        missing();
        cwuser.out_line(view.join_variants(list));
        n = int_enter();
    }
    return n;
}
