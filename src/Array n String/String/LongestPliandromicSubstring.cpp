// 5. Longest Palindromic Substring(https://leetcode.com/problems/longest-palindromic-substring
// Tags: #medium #string
// Efficiency: Time Complexity O(n^2), Space Complexity O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int l = 0, r = 0, max_len = 0, ptr = -1;

        for (int i = 0; i < s.length(); i++)
        {
            l = r = i;

            while (l >= 0 && r < s.length() && s[l] == s[r])
            {
                if (max_len < (r - l + 1))
                {
                    ptr = l;
                    max_len = r - l + 1;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r])
            {
                if (max_len < (r - l + 1))
                {
                    ptr = l;
                    max_len = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(ptr, max_len);
    }
};

int main()
{
    Solution solution;
    string input = "cbbd";

    cout << solution.longestPalindrome(input) << endl;
}