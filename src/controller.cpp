#include "controller.h"

Controller::Controller(CWUser& cwu, View& v, Model& m)
    : cwuser(cwu), view(v), model(m) {}

void Controller::run() { db_work(); }

void Controller::db_work() {
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

void Controller::db_task1() {
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> db_list = model.database_list();
    std::string variants = view.join_variants(db_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (model.database_connect(id)) {
        cwuser.out_line(variants);
        id = int_enter();
    }
    if (id) {
        cwuser.out_line(view.repeat_new_lines(1));
        table_work();
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::db_task2() {
    cwuser.out_line(view.DB_NAME_PROMPT);
    std::string db_name = cwuser.inp_word();
    while (model.create_database(db_name)) {
        cwuser.out_line(view.NAME_ALREADY_EXISTS);
        cwuser.out_line(view.DB_NAME_PROMPT);
        db_name = cwuser.inp_word();
    }
    cwuser.out_line(view.SUCCESS_MSG);
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::db_task3() {
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> db_list = model.database_list();
    std::string variants = view.join_variants(db_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (model.delete_database(id)) {
        cwuser.out_line(variants);
        id = int_enter();
    }
    if (id) {
        cwuser.out_line(view.SUCCESS_MSG);
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::db_task4() {
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> db_list = model.database_list();
    std::string variants = view.join_variants(db_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (!model.in_range(id, db_list.size() - 1)) {
        cwuser.out_line(variants);
        id = int_enter();
    }
    if (id) {
        cwuser.out_line(view.DB_NAME_PROMPT);
        std::string name = cwuser.inp_word();
        int query = model.rename_database(id, name);
        if (query == 0) {
            cwuser.out_line(view.SUCCESS_MSG);
        } else {
            cwuser.out_line(view.ERROR_MSG);
        }
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::table_work() {
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

void Controller::table_task1() {
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> table_list = model.table_list();
    std::string variants = view.join_variants(table_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (model.table_connect(id)) {
        cwuser.out_line(variants);
        id = int_enter();
    }
    if (id) {
        cwuser.out_line(view.repeat_new_lines(1));
        note_work();
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::table_task2() {
    cwuser.out_line(view.TABLE_NAME_PROMPT);
    std::string table_name = cwuser.inp_word();
    while (model.create_table(table_name)) {
        cwuser.out_line(view.NAME_ALREADY_EXISTS);
        cwuser.out_line(view.TABLE_NAME_PROMPT);
        table_name = cwuser.inp_word();
    }
    cwuser.out_line(view.SUCCESS_MSG);
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::table_task3() {
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> table_list = model.table_list();
    std::string variants = view.join_variants(table_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (model.delete_table(id)) {
        cwuser.out_line(variants);
        id = int_enter();
    }
    if (id) {
        cwuser.out_line(view.SUCCESS_MSG);
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::table_task4() {    
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> db_list = model.table_list();
    std::string variants = view.join_variants(db_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (!model.in_range(id, db_list.size() - 1)) {
        cwuser.out_line(variants);
        id = int_enter();
    }
    if (id) {
        cwuser.out_line(view.TABLE_NAME_PROMPT);
        std::string name = cwuser.inp_word();
        int query = model.rename_table(id, name);
        if (query == 0) {
            cwuser.out_line(view.SUCCESS_MSG);
        } else {
            cwuser.out_line(view.ERROR_MSG);
        }
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::note_work() {
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

void Controller::note_task1() {
    cwuser.out_line(view.SEARCH_PROMPT);
    std::string search = cwuser.inp_word();
    std::vector<note> note_list = model.search_note(search);
    std::string line = view.notes_to_line(note_list);
    cwuser.out_line(line);
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::note_task2() {
    cwuser.out_line(view.TEXT_PROMPT);
    std::string text = cwuser.inp_text();
    cwuser.out_line(view.KEYWORDS_PROMPT);
    std::string keywords = cwuser.inp_text();
    cwuser.out_line(view.repeat_new_lines(1));
    model.create_note(text, keywords);
}

void Controller::note_task3() {
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<note> notes_list = model.notes_list();
    std::vector<std::string> var_list = view.notes_to_lines(notes_list);
    std::string variants = view.join_variants(var_list);
    cwuser.out_line(variants);
    int id = int_enter();
    while (model.delete_note(id)) {
        cwuser.out_line(variants);
        id = int_enter();
    }
    if (id) {
        cwuser.out_line(view.SUCCESS_MSG);
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::note_task4() {
    cwuser.out_line(view.NOTE_ID_PROMPT);
    int id = int_enter();
    cwuser.out_line(view.TEXT_PROMPT);
    std::string text = cwuser.inp_text();
    cwuser.out_line(view.KEYWORDS_PROMPT);
    std::string keywords = cwuser.inp_text();
    if (model.update_note(id, text, keywords)) {
        cwuser.out_line(view.ERROR_MSG);
    } else {
        cwuser.out_line(view.SUCCESS_MSG);
    }
}

void Controller::note_task5() {
    cwuser.out_line(view.NOTE_ID_PROMPT);
    int id = int_enter();
    note rec;
    while (model.read_note(id, rec)) {
        cwuser.out_line(view.NOTE_ID_PROMPT);
        id = int_enter();
    }
    if (id) {
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
