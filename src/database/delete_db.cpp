#include "database/delete_db.h"

void db::delete_entry(SQLite::Database &db, const std::string &id) {
    SQLite::Transaction t(db);
        db.exec("DELETE FROM todos WHERE id = '" + id + "'");
    t.commit();
}