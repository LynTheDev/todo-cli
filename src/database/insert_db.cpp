#include "database/insert_db.h"

void db::insert(SQLite::Database &db, const std::string &todo) {
    SQLite::Transaction t(db);
        std::string todo_id = comp::make_id();
        std::string m = comp::get_time_as_string();

        std::string q = "INSERT INTO todos (id, text, date) VALUES (\'" + todo_id + "\', \'" + todo + "\', \'" + m + "\')";
        db.exec(q);
    t.commit();
}