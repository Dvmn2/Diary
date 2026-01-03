#include "model.h"

Model::Model(std::string path) {
    std::filesystem::path executable_path(path);
    std::filesystem::path main_path = executable_path.parent_path();
    Data_path = main_path.string() + "\\Diarys";
    std::filesystem::create_directory(Data_path);
}

void Model::db_connect(std::string path) {
    db = std::make_unique<SQLite::Database>(
        path, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
}

void Model::add_el_data(int a) {}

void Model::add_data(std::vector<int> a) {}

int Model::get_el_data(int i) { return 1; }

std::vector<int> Model::get_data() { return {1, 2}; }
