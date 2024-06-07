#include <iostream>

#include "./lib/headers/lru_cache.hpp"

using namespace std;

int main() {
    LRUCache cache;

    cache.set("1", "Mayank");
    cache.set("2", "Shalu");
    cache.set("3", "Komal");
    cache.set("4", "Pankaj");

    cout << "Hello World!";
}
