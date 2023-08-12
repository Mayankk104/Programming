// 1209. Remove All Adjacent Duplicates in String II https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
#include <bits/stdc++.h>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int n = s.size();
        if (n < k)
            return s;

        stack<pair<char, int>> stk;

        for (int i = 0; i < s.length(); i++)
        {
            if (stk.empty() or stk.top().first != s[i])
            {
                stk.push({s[i], 1});
            }
            else
            {
                auto prev = stk.top();
                stk.pop();
                stk.push({s[i], prev.second + 1});
            }

            if (stk.top().second == k)
                stk.pop();
        }

        string ans = "";
        while (!stk.empty())
        {
            auto cur = stk.top();
            stk.pop();
            while (cur.second--)
            {
                ans.push_back(cur.first);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.removeDuplicates("yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy", 4);
}