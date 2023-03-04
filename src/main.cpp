#include <SQLiteCpp/Database.h>
#include <iostream>
#include <lyra/lyra.hpp>
#include <boost/dll/runtime_symbol_info.hpp>

#include "database/insert_db.h"
#include "database/delete_db.h"
#include "database/fetchid.h"
#include "database/fetchall.h"

int main(int argc, char *argv[]) {
    // Open database in read-write
    auto db_name = (boost::dll::program_location().parent_path() / "data" / "todo_db.db").generic_string();
    SQLite::Database db(db_name, SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);

    // Old way of random
    srand(time(nullptr));

    // Parsing/creating args/commands
    std::string insert = "nil";
    std::string delete_query = "nil";
    std::string get_id = "nil";
    bool help = false;
    bool get_all = false;

    auto cli = lyra::cli() |
            lyra::opt(insert, "todo")
            ["-i"]["--insert"]
            ("Add todo to the database") |

            lyra::opt(delete_query, "id")
            ["-d"]["--delete"]
            ("Delete todo from the database") |

            lyra::opt(get_id, "id")
            ["-g"]["--get"]
            ("Get a specific todo using it's id.") |

            lyra::opt(get_all)
            ["-a"]["--getall"]
            ("Get all todos.") |

            lyra::help(help)
            ("Show program description.");

    auto result = cli.parse( { argc, argv } );
    if (!result) {
        std::cerr << "Error in command line: " << result.message() << std::endl;
    return -1;
    }

    if (help || argc == 1) {
        std::cout << cli << '\n';
        return 0;
    }

    // Good null checking Nattie....
    if (delete_query != "nil")
        db::delete_entry(db, delete_query);

    if (insert != "nil")
        db::insert(db, insert);

    if (get_id != "nil")
        db::fetch_id(db, get_id);

    if(get_all)
        db::fetch(db);

return 0;
}
