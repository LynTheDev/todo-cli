#include "database/fetchid.h"

void db::fetch_id(SQLite::Database &db, const std::string &id) {
    std::string qs = "SELECT * FROM todos WHERE id = ?";

    SQLite::Statement q(db, qs);
    q.bind(1, id);

    while (q.executeStep()) {
        const char *id_t = q.getColumn(0);
        const char *value = q.getColumn(1);
        const char *date = q.getColumn(2);

        std::cout << "\033[95m" << id_t << ":\033[0m"
        << " \033[94m" << value << "\033[0m"
        << " \033[92mat: " << date << "\033[0m";
    }
}