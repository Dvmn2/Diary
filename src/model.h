#pragma once

#include <SQLiteCpp/SQLiteCpp.h>

#include <filesystem>
#include <vector>

class Model {
   public:
    Model(std::string path);

    std::string Data_path = "";
    
    std::unique_ptr<SQLite::Database> db;

    void db_connect(std::string path);
    void add_el_data(int a);
    void add_data(std::vector<int> a);
    int get_el_data(int i);
    std::vector<int> get_data();
};
