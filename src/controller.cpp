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
            default:
                missing();
                break;
        }

        cwuser.out_line(variants);
        task = int_enter();
    }
}

void Controller::db_task1() {
    std::vector<std::string> list = model.db_list();
    cwuser.out_line(view.repeat_new_lines(1));
    int list_num = select_from_list(list);
    if (list_num != 0) {
        std::string dbname = list[list_num - 1];
        model.db_connect(dbname);
        cwuser.out_line(view.SUCCESS_MSG);
        cwuser.out_line(view.repeat_new_lines(1));
        table_work();
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::db_task2() {
    std::vector<std::string> list = model.db_list();
    cwuser.out_line(view.DB_NAME_PROMPT);
    std::string dbname = cwuser.inp_word();
    auto id = std::find(list.begin(), list.end(), dbname);
    while (id != list.end()) {
        cwuser.out_line(view.NAME_ALREADY_EXISTS);
        cwuser.out_line(view.DB_NAME_PROMPT);
        dbname = cwuser.inp_word();
        id = std::find(list.begin(), list.end(), dbname);
    }
    model.db_connect(dbname);
    cwuser.out_line(view.SUCCESS_MSG);
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::db_task3() {
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> list = model.db_list();
    int list_num = select_from_list(list);
    if (list_num != 0) {
        std::string dbname = list[list_num - 1];
        model.db_delete(dbname);
        cwuser.out_line(view.SUCCESS_MSG);
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
            default:
                missing();
                break;
        }

        cwuser.out_line(variants);
        task = int_enter();
    }
}

void Controller::table_task1() {
    std::vector<std::string> list = model.table_list();
    cwuser.out_line(view.repeat_new_lines(1));
    int list_num = select_from_list(list);
    if (list_num != 0) {
        std::string name = list[list_num - 1];
        model.table_name = name;
        cwuser.out_line(view.SUCCESS_MSG);
        cwuser.out_line(view.repeat_new_lines(1));
        note_work();
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::table_task2() {
    std::vector<std::string> list = model.table_list();
    cwuser.out_line(view.TABLE_NAME_PROMPT);
    std::string name = cwuser.inp_word();
    auto id = std::find(list.begin(), list.end(), name);
    while (id != list.end()) {
        cwuser.out_line(view.NAME_ALREADY_EXISTS);
        cwuser.out_line(view.TABLE_NAME_PROMPT);
        name = cwuser.inp_word();
        id = std::find(list.begin(), list.end(), name);
    }
    model.create_table(name);
    cwuser.out_line(view.SUCCESS_MSG);
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::table_task3() {
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::string> list = model.table_list();
    int list_num = select_from_list(list);
    if (list_num != 0) {
        std::string name = list[list_num - 1];
        model.delete_table(name);
        cwuser.out_line(view.SUCCESS_MSG);
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
    std::string line = view.notes_to_line(model.find_note(search));
    cwuser.out_line(line);
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::note_task2() {
    cwuser.out_line(view.TEXT_PROMPT);
    std::string note = cwuser.inp_text();
    cwuser.out_line(view.repeat_new_lines(1));
    cwuser.out_line(view.KEYWORDS_PROMPT);
    std::string keywords = cwuser.inp_text();
    cwuser.out_line(view.repeat_new_lines(1));
    model.create_note(note, keywords);
}

void Controller::note_task3() {
    cwuser.out_line(view.repeat_new_lines(1));
    std::vector<std::vector<std::string>> list = model.note_list();
    std::vector<std::string> variants = view.flatten_note_list(list);
    int list_num = select_from_list(variants);
    if (list_num != 0) {
        model.delete_note(list_num);
        cwuser.out_line(view.SUCCESS_MSG);
    }
    cwuser.out_line(view.repeat_new_lines(1));
}

void Controller::note_task4() {
    cwuser.out_line(view.NOTE_ID_PROMPT);
    int id = int_enter();
    cwuser.out_line(view.TEXT_PROMPT);
    std::string note = cwuser.inp_text();
    cwuser.out_line(view.KEYWORDS_PROMPT);
    std::string keywords = cwuser.inp_text();
    model.edit_note(std::to_string(id), note, keywords);
}

void Controller::note_task5() {
    cwuser.out_line(view.NOTE_ID_PROMPT);
    int id = int_enter();
    std::vector<std::string> list = model.read_note(std::to_string(id));
    for (int i = 0; i < list.size(); i++) {
        cwuser.out_line(list[i] + "\n");
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
