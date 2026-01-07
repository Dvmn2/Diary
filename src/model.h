#pragma once

#include "db_manager.h"
#include "note_manager.h"
#include "structures.h"
#include "table_manager.h"

class Model {
   private:
    DatabaseManager& DatabaseM;
    TableManager& TableM;
    NoteManager& NoteM;

    std::unique_ptr<SQLite::Database> database;
    std::string table;

   public:
    Model(DatabaseManager& dbm, TableManager& tm, NoteManager& nm);

    int database_connect(int id);
    std::vector<std::string> database_list();
    int create_database(std::string& name);
    int delete_database(int id);

    int table_connect(int id);
    std::vector<std::string> table_list();
    int create_table(std::string& name);
    int delete_table(int id);

    std::vector<note> notes_list();
    std::vector<note> search_note(const std::string& text);
    void create_note(const std::string& text, const std::string& keywords);
    int delete_note(int id);
    int update_note(int id, const std::string& text, const std::string& keywords);
    int read_note(int id, note& rec);

    bool in_range(int search, int a);
    bool in_range(int search, int a, int b);
};
