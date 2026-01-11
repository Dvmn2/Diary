#include "model.h"

Model::Model(DatabaseManager& dbm, TableManager& tm, NoteManager& nm)
    : DatabaseM(dbm), TableM(tm), NoteM(nm) {}

int Model::database_connect(int id) {
    if (!id) {
        return 0;
    }
    id--;
    std::vector<std::string> list = DatabaseM.list_databases();
    if (!in_range(id, list.size() - 1)) {
        return 1;
    }
    database = std::make_unique<SQLite::Database>(
        DatabaseM.full_path(list[id]), SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    return 0;
}

std::vector<std::string> Model::database_list() { return DatabaseM.list_databases(); }

int Model::create_database(std::string& name) {
    std::vector<std::string> list = DatabaseM.list_databases();
    auto id = std::find(list.begin(), list.end(), name);
    if (id != list.end()) {
        return 1;
    }
    DatabaseM.create_database(name);
    return 0;
}

int Model::delete_database(int id) {
    if (!id) {
        return 0;
    }
    id--;
    std::vector<std::string> list = DatabaseM.list_databases();
    if (!in_range(id, list.size() - 1)) {
        return 1;
    }
    database.reset();
    DatabaseM.delete_database(list[id]);
    return 0;
}

int Model::rename_database(int id, const std::string& new_name) {
    if (!id) {
        return 0;
    }
    id--;
    std::vector<std::string> list = DatabaseM.list_databases();
    if (!in_range(id, list.size() - 1)) {
        return 1;
    }
    auto id2 = std::find(list.begin(), list.end(), new_name);
    if (id2 != list.end()) {
        return 2;
    }
    DatabaseM.rename_database(list[id], new_name);
    return 0;
}

int Model::table_connect(int id) {
    if (!id) {
        return 0;
    }
    id--;
    TableM.connect(database);
    std::vector<std::string> list = TableM.list_tables();
    if (!in_range(id, list.size() - 1)) {
        TableM.disconnect(database);
        return 1;
    }
    table = list[id];
    TableM.disconnect(database);
    return 0;
}

std::vector<std::string> Model::table_list() {
    TableM.connect(database);
    std::vector<std::string> ret = TableM.list_tables();
    TableM.disconnect(database);
    return ret;
}

int Model::create_table(std::string& name) {
    if (name == "table") {
        return 1;
    }
    TableM.connect(database);
    std::vector<std::string> list = TableM.list_tables();
    auto id = std::find(list.begin(), list.end(), name);
    if (id != list.end()) {
        TableM.disconnect(database);
        return 1;
    }
    TableM.create_table(name);
    TableM.disconnect(database);
    return 0;
}

int Model::delete_table(int id) {
    if (!id) {
        return 0;
    }
    id--;
    TableM.connect(database);
    std::vector<std::string> list = TableM.list_tables();
    if (!in_range(id, list.size() - 1)) {
        TableM.disconnect(database);
        return 1;
    }
    TableM.drop_table(list[id]);
    TableM.disconnect(database);
    return 0;
}

int Model::rename_table(int id, const std::string& new_name) {
    if (!id) {
        return 0;
    }
    if (new_name == "table") {
        return 1;
    }
    TableM.connect(database);
    id--;
    std::vector<std::string> list = TableM.list_tables();
    if (!in_range(id, list.size() - 1)) {
        TableM.disconnect(database);
        return 1;
    }
    auto id2 = std::find(list.begin(), list.end(), new_name);
    if (id2 != list.end()) {
        TableM.disconnect(database);
        return 2;
    }
    TableM.rename_table(list[id], new_name);
    TableM.disconnect(database);
    return 0;
}

std::vector<note> Model::notes_list() {
    NoteM.connect(database, table);
    std::vector<note> ret = NoteM.list_notes();
    NoteM.disconnect(database);
    return ret;
}

std::vector<note> Model::search_note(const std::string& text) {
    NoteM.connect(database, table);
    std::vector<note> notes = NoteM.search(text);
    NoteM.disconnect(database);
    return notes;
}

void Model::create_note(const std::string& text, const std::string& keywords) {
    NoteM.connect(database, table);
    NoteM.create(text, keywords);
    NoteM.disconnect(database);
}

int Model::delete_note(int id) {
    if (!id) {
        return 0;
    }
    NoteM.connect(database, table);
    int max_id = NoteM.max_id();
    if (!in_range(id, max_id)) {
        NoteM.disconnect(database);
        return 1;
    }
    NoteM.remove(id);
    NoteM.disconnect(database);
    return 0;
}

int Model::update_note(int id, const std::string& text, const std::string& keywords) {
    if (!id) {
        return 0;
    }
    NoteM.connect(database, table);
    int max_id = NoteM.max_id();
    if (!in_range(id, max_id)) {
        NoteM.disconnect(database);
        return 1;
    }
    NoteM.update(id, text, keywords);
    NoteM.disconnect(database);
    return 0;
}

int Model::read_note(int id, note& rec) {
    if (!id) {
        return 0;
    }
    NoteM.connect(database, table);
    int max_id = NoteM.max_id();
    if (!in_range(id, max_id)) {
        NoteM.disconnect(database);
        return 1;
    }
    rec = NoteM.read(id);
    NoteM.disconnect(database);
    return 0;
}

bool Model::in_range(int search, int a) { return search >= 0 && search <= a; }

bool Model::in_range(int search, int a, int b) { return search >= a && search <= b; }
