#include "db_manager.h"

DatabaseManager::DatabaseManager(const std::string& path) {
    std::filesystem::path exe_path(path);
    std::filesystem::path main_path = exe_path.parent_path();
    base_path = main_path.string() + "/Diarys";
    std::filesystem::create_directory(base_path);
}

void DatabaseManager::create_database(const std::string& name) {
    std::unique_ptr<SQLite::Database> database = std::make_unique<SQLite::Database>(
        full_path(name), SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    database.reset();
}

void DatabaseManager::delete_database(const std::string& name) {
    std::filesystem::remove(full_path(name));
}

void DatabaseManager::rename_database(const std::string& old_name,
                                      const std::string& new_name) {
    std::filesystem::path old_path = full_path(old_name);
    std::filesystem::path new_path = full_path(new_name);
    std::filesystem::rename(old_path, new_path);
}

std::vector<std::string> DatabaseManager::list_databases() {
    std::vector<std::string> result;
    for (const auto& entry : std::filesystem::directory_iterator(base_path)) {
        if (entry.path().extension() == EXT)
            result.push_back(entry.path().stem().string());
    }
    return result;
}

std::string DatabaseManager::full_path(const std::string& name) {
    return base_path + "/" + name + EXT;
}

std::string DatabaseManager::base_path_str() { return base_path; }
