// Leetcode: 242. Valid Anagram (https://leetcode.com/problems/valid-anagram/)
// Tags: #easy
// Efficiency: Time Complexity O(n+m), Space Complexity O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> map;

        int s_size = s.length();
        int t_size = t.length();

        for (int i = 0; i < s_size; i++)
        {
            map[s[i]]++;
        }

        for (int i = 0; i < t_size; i++)
        {
            if (--map[t[i]] < 0)
            {
                return false;
            }
        }

        for (auto x : map)
        {
            if (x.second > 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    bool output;

    output = solution.isAnagram(s, t);

    cout << output;
}