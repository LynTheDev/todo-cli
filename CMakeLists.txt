cmake_minimum_required(VERSION 3.10)
project(todo)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/SQLiteCpp)
add_subdirectory(external/Lyra)
find_package(Boost REQUIRED COMPONENTS filesystem)

file(COPY data DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

add_executable(todo
        src/main.cpp
        src/components/make_id.cpp
        include/make_id.h
        include/database/insert_db.h
        src/database/insert_db.cpp
        src/components/get_time.cpp
        include/get_time.h
        include/database/delete_db.h
        src/database/delete_db.cpp
        include/database/fetchall.h
        src/database/fetchall.cpp
        src/database/fetchid.cpp
        include/database/fetchid.h
)

target_include_directories(todo PRIVATE
    include/
)

target_link_libraries(todo PRIVATE
    sqlite3
    SQLiteCpp

    lyra

    Boost::headers
    Boost::filesystem
)