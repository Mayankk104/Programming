#include <bits/stdc++.h>

#include "./lib/headers/tries.hpp"

using namespace std;

int main() {
    bool isPresent;
    Trie trie;
    vector<string> words = {"draw"};
    vector<string> quries = {"mayank", "draw"};

    for (string word : words)
        trie.addWord(word);

    for (string word : quries) {
        isPresent = trie.isWordPresent(word);
        if (isPresent) cout << word << " is present" << endl;
    }
}