
#ifndef CLI_TODO_DELETE_DB_H
#define CLI_TODO_DELETE_DB_H

#include "SQLiteCpp/Database.h"
#include "SQLiteCpp/Transaction.h"

namespace db {
    void delete_entry(SQLite::Database &db, const std::string& id);
}

#endif
