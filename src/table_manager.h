#pragma once

#include <SQLiteCpp/SQLiteCpp.h>

#include <memory>
#include <string>
#include <vector>

class TableManager {
   public:
    void connect(std::unique_ptr<SQLite::Database>& databasei);
    void disconnect(std::unique_ptr<SQLite::Database>& databasei);

    void create_table(const std::string& name);
    void drop_table(const std::string& name);
    void rename_table(const std::string& name1, const std::string& name2);
    std::vector<std::string> list_tables();

   private:
    std::unique_ptr<SQLite::Database> database;
};
