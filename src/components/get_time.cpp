#include "get_time.h"

std::string comp::get_time_as_string() {
    std::string time_str;

    time_t now = time(nullptr);
    tm *lc = localtime(&now);

    // Time conversion works weirdly in c/c++, so we're moving from 1990 LOL
    int day = lc->tm_mday;
    int month = 1 + lc->tm_mon;
    int year = 1900 + lc->tm_year;

    time_str = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
return time_str;
}