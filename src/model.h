#pragma once

#include <SQLiteCpp/SQLiteCpp.h>

#include <filesystem>
#include <vector>
#include <string>
#include <ctime>

class Model {
   public:
    Model(std::string path);

    std::string Data_path = "";
    std::string table_name = "";
    
    std::unique_ptr<SQLite::Database> db;

    void db_connect(std::string path);
    void db_delete(std::string name);
    std::vector<std::string> db_list();

    void select_table(std::string name);
    void create_table(std::string name);
    void delete_table(std::string id);
    std::vector<std::string> table_list();

    std::vector<std::vector<std::string>> find_note(std::string search);
    void create_note(std::string note, std::string keywords);
    void delete_note(std::string id);
    void edit_note(std::string id, std::string note, std::string keywords);
    std::vector<std::string> read_note(std::string id);
    std::vector<std::vector<std::string>> note_list();
};
