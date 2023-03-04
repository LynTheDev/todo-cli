#ifndef CLI_TODO_INSERT_DB_H
#define CLI_TODO_INSERT_DB_H

#include "SQLiteCpp/Database.h"
#include "SQLiteCpp/Transaction.h"
#include "make_id.h"
#include "get_time.h"

namespace db {
    void insert(SQLite::Database &db, const std::string& todo);
}

#endif
