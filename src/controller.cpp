#include "controller.h"

Controller::Controller(CWUser* cwu, View* v, Model* m) {
    cwuser = cwu;
    view = v;
    model = m;
}

void Controller::run() {
    std::string variants = view->get_variants();
    cwuser->output(variants);
    int task = cwuser->inp_array(1)[0];
    while (task != 0) {
        switch (task) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            default:
                missing();
                break;
        }

        cwuser->output(variants);
        task = cwuser->inp_array(1)[0];
    }
}

void Controller::task1() {
    cwuser->output(view->get_arr_len());
    int len = cwuser->inp_array(1)[0];
    cwuser->output(view->get_arr_req());
    std::vector<int> NewData = cwuser->inp_array(len);
    model->add_data(NewData);
    cwuser->output(view->get_msg_ending(1));
}

void Controller::task2() {
    cwuser->output(view->get_el_req());
    int n = cwuser->inp_array(1)[0];
    model->add_el_data(n);
    cwuser->output(view->get_msg_ending(1));
}

void Controller::task3() {
    std::vector<int> NewData = model->get_data();
    cwuser->output(view->arr_to_line(NewData));
    cwuser->output(view->get_msg_ending(2));
}

void Controller::task4() {
    cwuser->output(view->get_el_id());
    int i = cwuser->inp_array(1)[0];
    int el = model->get_el_data(i - 1);
    cwuser->output(view->el_to_line(el));
    cwuser->output(view->get_msg_ending(2));
}

void Controller::missing() {
    cwuser->output(view->get_missing_msg());
    cwuser->output(view->get_msg_ending(1));
}
