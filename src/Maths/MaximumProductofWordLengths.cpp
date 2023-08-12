// leetcode: 318. Maximum Product of Word Lengths https://leetcode.com/problems/maximum-product-of-word-lengths/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<string> &words) {
        unordered_map<int, int> table;
        int words_vector_length = words.size(), maxCount = 0;

        for (int i = 0; i < words_vector_length; i++) {
            int answer = 0;
            for (auto character : words[i]) {
                answer = answer | 1 << (character - 'a');
                table[i] = answer;
            }
        }

        for (int i = 0; i < words_vector_length; i++)
            for (int j = i + 1; j < words_vector_length; j++) {
                int lengthProduct = words[i].length() * words[j].length();
                if ((table[i] & table[j]) == 0)
                    maxCount = max(maxCount, lengthProduct);
            }

        return maxCount;
    }
};

int main() {
    Solution s;
    vector<string> input = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << s.maxProduct(input);
}