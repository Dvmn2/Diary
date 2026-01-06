#include "model.h"

Model::Model(std::string path) {
    std::filesystem::path executable_path(path);
    std::filesystem::path main_path = executable_path.parent_path();
    Data_path = main_path.string() + "/Diarys";
    std::filesystem::create_directory(Data_path);
}

void Model::db_connect(std::string name) {
    std::string path = Data_path + "/" + name + ".db3";
    db = std::make_unique<SQLite::Database>(
        path, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
}

void Model::db_delete(std::string name) {
    db.reset();
    std::string path = Data_path + "/" + name + ".db3";
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

std::vector<std::vector<std::string>> Model::find_note(std::string search) {
    std::vector<std::vector<std::string>> results = {};

    bool is_number =
        !search.empty() && std::all_of(search.begin(), search.end(), ::isdigit);

    SQLite::Statement query(
        *db, is_number ? "SELECT id, note, keywords, time FROM " + table_name +
                             " WHERE id = ?"
                       : "SELECT id, note, keywords, time FROM " + table_name +
                             " WHERE note LIKE ? OR keywords LIKE ?");

    if (is_number) {
        query.bind(1, std::stoi(search));
    } else {
        std::string pattern = "%" + search + "%";
        query.bind(1, pattern);
        query.bind(2, pattern);
    }

    while (query.executeStep()) {
        results.push_back({std::to_string(query.getColumn(0).getInt()),
                           query.getColumn(1).getString(),
                           query.getColumn(2).getString(),
                           query.getColumn(3).getString()});
    }

    return results;
}

void Model::create_note(std::string note, std::string keywords) {
    std::string time = current_time();
    SQLite::Statement query(
        *db, "INSERT INTO " + table_name + " (note, keywords, time) VALUES (?, ?, ?)");
    query.bind(1, note);
    query.bind(2, keywords);
    query.bind(3, time);
    query.exec();
}

void Model::delete_note(int id) {
    SQLite::Statement deleteQuery(*db, "DELETE FROM " + table_name + " WHERE id = ?");
    deleteQuery.bind(1, id);
    deleteQuery.exec();

    SQLite::Statement updateQuery(
        *db, "UPDATE " + table_name + " SET id = id - 1 WHERE id > ?");
    updateQuery.bind(1, id);
    updateQuery.exec();
}

void Model::edit_note(std::string id, std::string note, std::string keywords) {
    std::string time = current_time();

    SQLite::Statement query(
        *db,
        "UPDATE " + table_name + " SET note = ?, keywords = ?, time =  ? WHERE id = ?");
    query.bind(1, note);
    query.bind(2, keywords);
    query.bind(3, time);
    query.bind(4, id);
    query.exec();
}

std::vector<std::string> Model::read_note(const std::string id) {
    SQLite::Statement query(
        *db, "SELECT id, note, keywords, time FROM " + table_name + " WHERE id = ?");

    query.bind(1, id);

    std::vector<std::string> list;

    if (query.executeStep()) {
        list.push_back(std::to_string(query.getColumn(0).getInt()));
        list.push_back(query.getColumn(1).getString());
        list.push_back(query.getColumn(2).getString());
        list.push_back(query.getColumn(3).getString());
    }

    return list;
}

std::vector<std::vector<std::string>> Model::note_list() {
    std::vector<std::vector<std::string>> list = {};
    SQLite::Statement query(*db, "SELECT * FROM " + table_name);
    while (query.executeStep()) {
        list.push_back({query.getColumn(1).getString(), query.getColumn(2).getString(),
                        query.getColumn(3).getString()});
    }

    return list;
}

std::string Model::current_time() {
    std::time_t t = std::time(nullptr);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%d.%m.%y %H:%M:%S", std::localtime(&t));
    return buf;
}
