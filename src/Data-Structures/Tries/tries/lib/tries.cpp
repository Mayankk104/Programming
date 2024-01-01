#include "./headers/tries.hpp"

void Trie::addWord(string word) {
    if (word.length() < 1) return;

    try {
        TrieNode* temp = this->rootnode;

        for (auto chr : word) {
            if (temp->map[chr] == nullptr) {
                temp->map[chr] = new TrieNode();
            }
            temp = temp->map[chr];
        }
        temp->count++;
    } catch (...) {
        cout << "An Error Occured While Inserting Word ⚠";
    }
}

bool Trie::isWordPresent(string word) {
    TrieNode* temp = this->rootnode;

    for (char chr : word) {
        if (temp->map[chr] == nullptr) return false;
        temp = temp->map[chr];
    }
    return temp->count > 0 ? true : false;
}

Trie::Trie() {
    rootnode = new TrieNode();
}