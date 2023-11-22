#pragma once
#include "./trienode.hpp"

class Trie {
   private:
    TrieNode* rootnode;

   public:
    Trie();
    void addWord(string word);
    bool isWordPresent(string word);
};