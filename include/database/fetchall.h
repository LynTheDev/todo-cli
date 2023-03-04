#ifndef TODO_FETCHALL_H
#define TODO_FETCHALL_H

#include "SQLiteCpp/Database.h"
#include "SQLiteCpp/Transaction.h"
#include <iostream>

namespace db {
    void fetch(SQLite::Database &db);
}

#endif
