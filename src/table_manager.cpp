#include "table_manager.h"

void TableManager::connect(std::unique_ptr<SQLite::Database>& databasei) {
    database = std::move(databasei);
}

void TableManager::disconnect(std::unique_ptr<SQLite::Database>& databasei) {
    databasei  = std::move(database);
}

void TableManager::create_table(const std::string& name) {
    database->exec("CREATE TABLE '" + name +
                  "' (id INTEGER PRIMARY KEY, note TEXT, keywords TEXT, time TEXT)");
}

void TableManager::drop_table(const std::string& name) {
    database->exec("DROP TABLE IF EXISTS '" + name + "'");
}

std::vector<std::string> TableManager::list_tables() {
    std::vector<std::string> tables;
    SQLite::Statement query(*database,
                            "SELECT name FROM sqlite_master WHERE type='table'");
    while (query.executeStep()) {
        tables.push_back(query.getColumn(0));
    }
    return tables;
}
