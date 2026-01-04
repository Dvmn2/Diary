#include "model.h"

Model::Model(std::string path) {
    std::filesystem::path executable_path(path);
    std::filesystem::path main_path = executable_path.parent_path();
    Data_path = main_path.string() + "\\Diarys";
    std::filesystem::create_directory(Data_path);
}

void Model::db_connect(std::string name) {
    std::string path = Data_path + "\\" + name + ".db3";
    db = std::make_unique<SQLite::Database>(
        path, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
}

void Model::add_el_data(int a) {
    db->exec("DROP TABLE IF EXISTS test");
    db->exec("CREATE TABLE test (id INTEGER PRIMARY KEY, value TEXT)");

    int nb = db->exec("INSERT INTO test VALUES (NULL, \"test\")");

    nb = db->exec("INSERT INTO test VALUES (NULL, \"second\")");

    nb = db->exec("UPDATE test SET value=\"second-updated\" WHERE id='2'");
    /*
    SQLite::Statement query(*db, "SELECT * FROM test");
    std::cout << "SELECT * FROM test :\n";
    while (query.executeStep()) {
        std::cout << "row (" << query.getColumn(0) << ", \"" << query.getColumn(1)
                  << "\")\n";
    }
    */
}

void Model::add_data(std::vector<int> a) {}

int Model::get_el_data(int i) { return 1; }

std::vector<int> Model::get_data() { return {1, 2}; }
