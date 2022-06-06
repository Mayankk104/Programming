#include <string>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int l = 0, r = 0;
        string subStr = "";

        for (int i = 0; i < s.length(); i++)
        {
            l = r = i;
            while (s[l] == s[r] && l >= 0 && r < s.length())
            {
                if (subStr.length() < s.substr(l, r).length())
                    subStr = s.substr(l, r - l + 1);

                l--;
                r++;
            }

            l = i;
            r = i + 1;

            while (s[l] == s[r] && l >= 0 && r < s.length())
            {
                if (subStr.length() < s.substr(l, r).length())
                    subStr = s.substr(l, r - l + 1);

                l--;
                r++;
            }
        }

        return subStr;
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("abab") << endl;
}