#pragma once

#include <SQLiteCpp/SQLiteCpp.h>

#include <filesystem>
#include <string>
#include <vector>

class DatabaseManager {
   public:
    DatabaseManager(const std::string& path);

    void create_database(const std::string& name);
    void delete_database(const std::string& name);
    void rename_database(const std::string& old_name, const std::string& new_name);
    std::vector<std::string> list_databases();

    std::string full_path(const std::string& name);
    std::string base_path_str();

    static constexpr const char* EXT = ".db3";

   private:
    std::string base_path;
};
