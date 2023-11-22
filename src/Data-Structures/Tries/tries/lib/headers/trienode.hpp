#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
   public:
    int count;
    unordered_map<char, TrieNode*> map;

    TrieNode() {
        this->count = 0;
    };
};