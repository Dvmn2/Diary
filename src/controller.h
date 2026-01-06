#pragma once

#include "cwuser.h"
#include "model.h"
#include "view.h"

class Controller {
   public:
    Controller(CWUser* cwuser, View* view, Model* model);

    CWUser* cwuser;
    View* view;
    Model* model;

    void run();

    void db_work();
    void db_task1();
    void db_task2();
    void db_task3();

    void table_work();
    void table_task1();
    void table_task2();
    void table_task3();

    void note_work();
    void note_task1();
    void note_task2();
    void note_task3();

    void missing();
    int int_enter();

};
