#pragma once

#include <SQLiteCpp/SQLiteCpp.h>

#include <ctime>
#include <string>
#include <vector>

#include "structures.h"

class NoteManager {
   public:
    void connect(std::unique_ptr<SQLite::Database>& databasei, std::string& tablei);
    void disconnect(std::unique_ptr<SQLite::Database>& databasei);

    std::vector<note> search(const std::string& text);
    void create(const std::string& text, const std::string& keywords);
    void remove(int id);
    void update(int id, const std::string& text, const std::string& keywords);
    note read(int id);

    std::vector<note> list_notes();
    int max_id();

    std::string current_time();
    std::string table_name();

   private:
    std::unique_ptr<SQLite::Database> database;
    std::string table;

    // explicit - запрещает неявноее преобразование типов
};
