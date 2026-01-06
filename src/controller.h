#pragma once

#include "cwuser.h"
#include "model.h"
#include "view.h"

class Controller {
   private:
    CWUser& cwuser;
    View& view;
    Model& model;

   public:
    Controller(CWUser& cwu, View& v, Model& m);

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
    void note_task4();
    void note_task5();

    void missing();
    int int_enter();
    int select_from_list(const std::vector<std::string>& list);
};
