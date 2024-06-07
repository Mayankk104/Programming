#pragma once

#include <string>

class LRUCache {
   public:
    std::string get(std::string str);
    void set(std::string key, std::string value);
};
