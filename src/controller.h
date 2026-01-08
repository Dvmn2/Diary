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

    void db_work();   // Database menu
    void db_task1();  // Select database
    void db_task2();  // Create database
    void db_task3();  // Delete database
    void db_task4();  // Rename database

    void table_work();   // Table menu
    void table_task1();  // Select table
    void table_task2();  // Create table
    void table_task3();  // Delete table
    void table_task4();  // Rename table

    void note_work();   // Note menu
    void note_task1();  // Search note
    void note_task2();  // Create note
    void note_task3();  // Delete note
    void note_task4();  // Update note
    void note_task5();  // Read note

    void missing();
    int int_enter();  // Enter int number
    int select_from_list(const std::vector<std::string>& list);
};
