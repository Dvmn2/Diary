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

void Model::db_delete(std::string name) {
    db.reset();
    std::string path = Data_path + "\\" + name + ".db3";
    remove(path.c_str());
}

std::vector<std::string> Model::db_list() {
    std::vector<std::string> Array = {};
    for (const auto& entry : std::filesystem::directory_iterator(Data_path)) {
        if (entry.path().extension().string() == ".db3")
            Array.push_back(entry.path().stem().string());
    }

    return Array;
}

void Model::select_table(std::string name) { table_name = name; }

void Model::create_table(std::string name) {
    db->exec("CREATE TABLE " + name +
             " (id INTEGER PRIMARY KEY, note TEXT, keywords TEXT, time TEXT)");
}

void Model::delete_table(std::string name) { db->exec("DROP TABLE IF EXISTS " + name); }

std::vector<std::string> Model::table_list() {
    std::vector<std::string> Array = {};
    SQLite::Statement query(*db, "SELECT name FROM sqlite_master WHERE type='table'");
    while (query.executeStep()) {
        Array.push_back(query.getColumn(0));
    }

    return Array;
}

void Model::find_note(std::string name) {}

void Model::create_note(std::string note, std::string keywords) {
    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);
    char out[50];

    strftime(out, 50, "%d.%m.%y %H:%M:%S", &datetime);
    std::string time{out};
    SQLite::Statement query(
        *db, "INSERT INTO " + table_name + " (note, keywords, time) VALUES (?, ?, ?)");
    query.bind(1, note);
    query.bind(2, keywords);
    query.bind(3, time);
    query.exec();
}

void Model::delete_note(std::string id) { db->exec("DELETE FROM " + table_name + " WHERE id == " + id); }

std::vector<std::vector<std::string>> Model::note_list() {
    std::vector<std::vector<std::string>> list = {};
    SQLite::Statement query(*db, "SELECT * FROM " + table_name);
    while (query.executeStep()) {
        list.push_back({query.getColumn(1).getString(), query.getColumn(2).getString(),
                        query.getColumn(3).getString()});
    }

    return list;
}

/*
    // test
    db->exec("DROP TABLE IF EXISTS test");
    db->exec("CREATE TABLE test (id INTEGER PRIMARY KEY, value TEXT)");

    db->exec("DROP TABLE IF EXISTS test2");
    db->exec("CREATE TABLE test2 (id INTEGER PRIMARY KEY, value TEXT)");

    db->exec("INSERT INTO test VALUES (NULL, \"test\")");

    db->exec("INSERT INTO test VALUES (NULL, \"second\")");

    db->exec("UPDATE test SET value=\"second-updated\" WHERE id='2'");

    SQLite::Statement query(*db, "SELECT * FROM test");
    while (query.executeStep()) {
        std::cout << "row (" << query.getColumn(0) << ", \"" << query.getColumn(1)
                  << "\")\n";
    }

    SQLite::Statement query2(*db, "SELECT name FROM sqlite_master WHERE type='table'");
    while (query2.executeStep()) {
        std::cout << "row (" << query2.getColumn(0) << ", \""  << "\")\n";
    }
*/