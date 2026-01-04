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
    void task1();
    void task2();
    void task3();
    void task4();
    void missing();

    void task5();
};
