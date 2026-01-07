#include "note_manager.h"

void NoteManager::connect(std::unique_ptr<SQLite::Database>& databasei,
                          std::string& tablei) {
    database = std::move(databasei);
    table = tablei;
}

void NoteManager::disconnect(std::unique_ptr<SQLite::Database>& databasei) {
    databasei = std::move(database);
    table = "";
}

std::vector<note> NoteManager::search(const std::string& text) {
    std::vector<note> results = {};
    bool is_number = !text.empty() && std::all_of(text.begin(), text.end(), ::isdigit);
    SQLite::Statement query(
        *database,
        is_number ? "SELECT id, note, keywords, time FROM " + table + " WHERE id = ?"
                  : "SELECT id, note, keywords, time FROM " + table +
                        " WHERE note LIKE ? OR keywords LIKE ?");
    if (is_number) {
        query.bind(1, std::stoi(text));
    } else {
        std::string pattern = "%" + text + "%";
        query.bind(1, pattern);
        query.bind(2, pattern);
    }
    while (query.executeStep()) {
        note part;
        part.id = query.getColumn(0).getInt();
        part.text = query.getColumn(1).getString();
        part.keywords = query.getColumn(2).getString();
        part.time = query.getColumn(3).getString();

        results.push_back(part);
    }
    return results;
}

void NoteManager::create(const std::string& text, const std::string& keywords) {
    std::string time = current_time();
    SQLite::Statement query(
        *database, "INSERT INTO " + table + " (note, keywords, time) VALUES (?, ?, ?)");
    query.bind(1, text);
    query.bind(2, keywords);
    query.bind(3, time);
    query.exec();
}

void NoteManager::remove(int id) {
    SQLite::Statement deleteQuery(*database, "DELETE FROM " + table + " WHERE id = ?");
    deleteQuery.bind(1, id);
    deleteQuery.exec();
    SQLite::Statement updateQuery(*database,
                                  "UPDATE " + table + " SET id = id - 1 WHERE id > ?");
    updateQuery.bind(1, id);
    updateQuery.exec();
}

void NoteManager::update(int id, const std::string& text, const std::string& keywords) {
    std::string time = current_time();
    SQLite::Statement query(
        *database,
        "UPDATE " + table + " SET note = ?, keywords = ?, time =  ? WHERE id = ?");
    query.bind(1, text);
    query.bind(2, keywords);
    query.bind(3, time);
    query.bind(4, id);
    query.exec();
}

note NoteManager::read(int id) {
    SQLite::Statement query(
        *database, "SELECT id, note, keywords, time FROM " + table + " WHERE id = ?");
    query.bind(1, id);
    note rec;
    if (query.executeStep()) {
        rec.id = query.getColumn(0).getInt();
        rec.text = query.getColumn(1).getString();
        rec.keywords = query.getColumn(2).getString();
        rec.time = query.getColumn(3).getString();
    }
    return rec;
}

std::vector<note> NoteManager::list_notes() {
    std::vector<note> list = {};
    SQLite::Statement query(*database, "SELECT * FROM " + table);
    while (query.executeStep()) {
        note part;
        part.id = query.getColumn(0).getInt();
        part.text = query.getColumn(1).getString();
        part.keywords = query.getColumn(2).getString();
        part.time = query.getColumn(3).getString();
        list.push_back(part);
    }
    return list;
}

int NoteManager::max_id() {
    SQLite::Statement query(*database, "SELECT MAX(id) FROM " + table);
    int id = 0;
    if (query.executeStep()) {
        auto col = query.getColumn(0);
        if (!col.isNull()) {
            id = col.getInt();
        }
    }
    return id;
}

std::string NoteManager::current_time() {
    std::time_t t = std::time(nullptr);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%d.%m.%y %H:%M:%S", std::localtime(&t));
    return buf;
}

std::string NoteManager::table_name() { return table; }