#include "controller.h"

Controller::Controller(CWUser& cwu, View& v, Model& m)
    : cwuser(cwu), view(v), model(m) {}

void Controller::run() { db_work(); }

void Controller::db_work() {
    std::string variants = view.get_db_variants();
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
    /*
    if (list.size() == 0) {
        cwuser.out_line(view.get_db_absent());
    } else if (list.size() == 1) {
        dbname = list[0];
        model.db_connect(dbname);
        cwuser.out_line(view.get_success());
        cwuser.out_line(view.get_space(1));
        table_work();
    } else {
    */
    cwuser.out_line(view.get_space(1));
    cwuser.out_line(view.get_self_variants(list));
    int list_num = int_enter();
    while (list_num < 0 || list_num > list.size()) {
        missing();
        cwuser.out_line(view.get_self_variants(list));
        list_num = int_enter();
    }
    if (list_num != 0) {
        std::string dbname = list[list_num - 1];
        model.db_connect(dbname);
        cwuser.out_line(view.get_success());
        cwuser.out_line(view.get_space(1));
        table_work();
    }
    //}
    cwuser.out_line(view.get_space(1));
}

void Controller::db_task2() {
    std::vector<std::string> list = model.db_list();
    cwuser.out_line(view.get_db_name_req());
    std::string dbname = cwuser.inp_word();
    auto id = std::find(list.begin(), list.end(), dbname);
    while (id != list.end()) {
        cwuser.out_line(view.get_already_exists());
        cwuser.out_line(view.get_db_name_req());
        dbname = cwuser.inp_word();
        id = std::find(list.begin(), list.end(), dbname);
    }
    model.db_connect(dbname);
    cwuser.out_line(view.get_success());
    cwuser.out_line(view.get_space(1));
}

void Controller::db_task3() {
    cwuser.out_line(view.get_space(1));
    std::vector<std::string> list = model.db_list();
    std::string variants = view.get_self_variants(list);
    cwuser.out_line(variants);
    int list_num = int_enter();
    while (list_num < 0 || list_num > list.size()) {
        missing();
        cwuser.out_line(variants);
        list_num = int_enter();
    }
    if (list_num != 0) {
        std::string dbname = list[list_num - 1];
        model.db_delete(dbname);
        cwuser.out_line(view.get_success());
    }
    cwuser.out_line(view.get_space(1));
}

void Controller::table_work() {
    std::string variants = view.get_table_variants();
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
    cwuser.out_line(view.get_space(1));
    cwuser.out_line(view.get_self_variants(list));
    int list_num = int_enter();
    while (list_num < 0 || list_num > list.size()) {
        missing();
        cwuser.out_line(view.get_self_variants(list));
        list_num = int_enter();
    }
    if (list_num != 0) {
        std::string name = list[list_num - 1];
        model.table_name = name;
        cwuser.out_line(view.get_success());
        cwuser.out_line(view.get_space(1));
        note_work();
    }
    cwuser.out_line(view.get_space(1));
}

void Controller::table_task2() {
    std::vector<std::string> list = model.table_list();
    cwuser.out_line(view.get_table_name_req());
    std::string name = cwuser.inp_word();
    auto id = std::find(list.begin(), list.end(), name);
    while (id != list.end()) {
        cwuser.out_line(view.get_already_exists());
        cwuser.out_line(view.get_table_name_req());
        name = cwuser.inp_word();
        id = std::find(list.begin(), list.end(), name);
    }
    model.create_table(name);
    cwuser.out_line(view.get_success());
    cwuser.out_line(view.get_space(1));
}

void Controller::table_task3() {
    cwuser.out_line(view.get_space(1));
    std::vector<std::string> list = model.table_list();
    std::string variants = view.get_self_variants(list);
    cwuser.out_line(variants);
    int list_num = int_enter();
    while (list_num < 0 || list_num > list.size()) {
        missing();
        cwuser.out_line(variants);
        list_num = int_enter();
    }
    if (list_num != 0) {
        std::string name = list[list_num - 1];
        model.delete_table(name);
        cwuser.out_line(view.get_success());
    }
    cwuser.out_line(view.get_space(1));
}

void Controller::note_work() {
    std::string variants = view.get_note_variants();
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
    cwuser.out_line(view.get_search_req());
    std::string search = cwuser.inp_word();
    std::string line = view.note_list_list_to_line(model.find_note(search));
    cwuser.out_line(line);
    cwuser.out_line(view.get_space(1));
}

void Controller::note_task2() {
    cwuser.out_line(view.get_text_req());
    std::string note = cwuser.inp_text();
    cwuser.out_line(view.get_keywords_req());
    std::string keywords = cwuser.inp_text();
    model.create_note(note, keywords);
}

void Controller::note_task3() {
    cwuser.out_line(view.get_space(1));
    std::vector<std::vector<std::string>> list = model.note_list();
    std::string variants =
        view.get_self_variants(view.note_list_list_to_note_list(list));
    cwuser.out_line(variants);
    int list_num = int_enter();
    while (list_num < 0 || list_num > list.size()) {
        missing();
        cwuser.out_line(variants);
        list_num = int_enter();
    }
    if (list_num != 0) {
        model.delete_note(std::to_string(list_num));
        cwuser.out_line(view.get_success());
    }
    cwuser.out_line(view.get_space(1));
}

void Controller::note_task4() {
    cwuser.out_line(view.get_note_id_req());
    int id = int_enter();
    cwuser.out_line(view.get_text_req());
    std::string note = cwuser.inp_text();
    cwuser.out_line(view.get_keywords_req());
    std::string keywords = cwuser.inp_text();
    model.edit_note(std::to_string(id), note, keywords);
}

void Controller::note_task5() {
    cwuser.out_line(view.get_note_id_req());
    int id = int_enter();
    std::vector<std::string> list = model.read_note(std::to_string(id));
    for (int i = 0; i < list.size(); i++) {
        cwuser.out_line(list[i] + "\n");
    }
    cwuser.out_line(view.get_space(1));
}

void Controller::missing() {
    cwuser.out_line(view.get_missing_msg());
    cwuser.out_line(view.get_space(1));
}

int Controller::int_enter() {
    std::string inp = cwuser.inp_word();
    int f = 1;
    int value;
    while (f) try {
            value = std::stoi(inp);
            f = 0;
        } catch (...) {
            cwuser.out_line(view.get_int_req());
            inp = cwuser.inp_word();
        }

    return value;
}
