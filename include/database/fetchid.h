#ifndef TODO_FETCHID_H
#define TODO_FETCHID_H

#include "SQLiteCpp/Database.h"
#include "SQLiteCpp/Transaction.h"
#include <iostream>

namespace db {
    void fetch_id(SQLite::Database &db, const std::string &id);
}

#endif
