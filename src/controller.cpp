#include "controller.h"

Controller::Controller(CWUser* cwu, View* v, Model* m) {
    cwuser = cwu;
    view = v;
    model = m;
}

void Controller::run() { db_work(); }

void Controller::db_work() {
    std::string variants = view->get_db_variants();
    cwuser->out_line(variants);
    int task = cwuser->inp_array(1)[0];
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

        cwuser->out_line(variants);
        task = cwuser->inp_array(1)[0];
    }
}

void Controller::db_task1() {
    std::vector<std::string> list = model->db_list();
    std::string dbname;
    /*
    if (list.size() == 0) {
        cwuser->out_line(view->get_db_absent());
    } else if (list.size() == 1) {
        dbname = list[0];
        model->db_connect(dbname);
        cwuser->out_line(view->get_success());
        cwuser->out_line(view->get_space(1));
        table_work();
    } else {
    */
    cwuser->out_line(view->get_space(1));
    cwuser->out_line(view->get_self_variants(list));
    int list_num = cwuser->inp_array(1)[0];
    while (list_num < 0 || list_num > list.size()) {
        missing();
        cwuser->out_line(view->get_self_variants(list));
        list_num = cwuser->inp_array(1)[0];
    }
    if (list_num != 0) {
        dbname = list[list_num - 1];
        model->db_connect(dbname);
        cwuser->out_line(view->get_success());
        cwuser->out_line(view->get_space(1));
        table_work();
    }
    //}
    cwuser->out_line(view->get_space(1));
}

void Controller::db_task2() {
    std::vector<std::string> list = model->db_list();
    cwuser->out_line(view->get_db_name_req());
    std::string dbname = cwuser->inp_word();
    auto id = std::find(list.begin(), list.end(), dbname);
    while (id != list.end()) {
        cwuser->out_line(view->get_already_exists());
        cwuser->out_line(view->get_db_name_req());
        dbname = cwuser->inp_word();
        id = std::find(list.begin(), list.end(), dbname);
    }
    model->db_connect(dbname);
    cwuser->out_line(view->get_success());
    cwuser->out_line(view->get_space(1));
}

void Controller::db_task3() {
    cwuser->out_line(view->get_space(1));
    std::vector<std::string> list = model->db_list();
    std::string variants = view->get_self_variants(list);
    cwuser->out_line(variants);
    int list_num = cwuser->inp_array(1)[0];
    while (list_num < 0 || list_num > list.size()) {
        missing();
        cwuser->out_line(variants);
        list_num = cwuser->inp_array(1)[0];
    }
    if (list_num != 0) {
        std::string dbname = list[list_num - 1];
        model->db_delete(dbname);
        cwuser->out_line(view->get_success());
    }
    cwuser->out_line(view->get_space(1));
}

void Controller::table_work() {
    std::string variants = view->get_table_variants();
    cwuser->out_line(variants);
    int task = cwuser->inp_array(1)[0];
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

        cwuser->out_line(variants);
        task = cwuser->inp_array(1)[0];
    }
}

void Controller::table_task1() {
    std::vector<std::string> list = model->table_list();
    cwuser->out_line(view->get_space(1));
    cwuser->out_line(view->get_self_variants(list));
    int list_num = cwuser->inp_array(1)[0];
    while (list_num < 0 || list_num > list.size()) {
        missing();
        cwuser->out_line(view->get_self_variants(list));
        list_num = cwuser->inp_array(1)[0];
    }
    if (list_num != 0) {
        std::string name = list[list_num - 1];
        model->table_name = name;
        cwuser->out_line(view->get_success());
        cwuser->out_line(view->get_space(1));
        note_work();
    }
    cwuser->out_line(view->get_space(1));
}

void Controller::table_task2() {
    std::vector<std::string> list = model->table_list();
    cwuser->out_line(view->get_table_name_req());
    std::string name = cwuser->inp_word();
    auto id = std::find(list.begin(), list.end(), name);
    while (id != list.end()) {
        cwuser->out_line(view->get_already_exists());
        cwuser->out_line(view->get_table_name_req());
        name = cwuser->inp_word();
        id = std::find(list.begin(), list.end(), name);
    }
    model->create_table(name);
    cwuser->out_line(view->get_success());
    cwuser->out_line(view->get_space(1));
}

void Controller::table_task3() {
    cwuser->out_line(view->get_space(1));
    std::vector<std::string> list = model->table_list();
    std::string variants = view->get_self_variants(list);
    cwuser->out_line(variants);
    int list_num = cwuser->inp_array(1)[0];
    while (list_num < 0 || list_num > list.size()) {
        missing();
        cwuser->out_line(variants);
        list_num = cwuser->inp_array(1)[0];
    }
    if (list_num != 0) {
        std::string name = list[list_num - 1];
        model->delete_note(name);
        cwuser->out_line(view->get_success());
    }
    cwuser->out_line(view->get_space(1));
}

void Controller::note_work() {
    std::string variants = view->get_note_variants();
    cwuser->out_line(variants);
    int task = cwuser->inp_array(1)[0];
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
            default:
                missing();
                break;
        }

        cwuser->out_line(variants);
        task = cwuser->inp_array(1)[0];
    }
}

void Controller::note_task1() {}

void Controller::note_task2() {}

void Controller::note_task3() {}

void Controller::missing() {
    cwuser->out_line(view->get_missing_msg());
    cwuser->out_line(view->get_space(1));
}
