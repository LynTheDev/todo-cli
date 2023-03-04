#include <make_id.h>

std::vector<char> can_pick = {
    'a','b','c','d','e','f',
    'g','h','i','j','k','l',
    'm','n','o','p','q','r',
    's','t','u','v','w','x',
    'y','z'
};


std::string comp::make_id() {
    std::string id;

    for (int i = 0; i <= 10; i++) {
        int index = rand() % can_pick.size();
        id += can_pick[index];
    }

return id;
}
