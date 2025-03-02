#include <bits/stdc++.h>

using namespace std;

class Solution {
   private:
    vector<vector<int>> dp;
    int recursion(string s1, int i1, string s2, int i2) {
        int result = 0;
        if (i1 >= s1.size() || i2 >= s2.size()) return 0;
        if (dp[i1][i2] != -1) return dp[i1][i2];

        if (s1[i1] == s2[i2]) {
            result = 1 + recursion(s1, i1 + 1, s2, i2 + 1);
            dp[i1][i2] = result;
            return result;
        }

        int max_sub_sequence_right = recursion(s1, i1 + 1, s2, i2);
        int max_sub_sequence_left = recursion(s1, i1, s2, i2 + 1);

        result = max(max_sub_sequence_left, max_sub_sequence_right);
        dp[i1][i2] = result;
        return result;
    }

   public:
    int longest_sub_sequence(string s1, string s2) {
        dp.assign(s1.size(), vector<int>(s2.size(), -1));
        return recursion(s1, 0, s2, 0);
    }
};

int main() {
    Solution solution;

#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    int testcases;

    cin >> testcases;

    while (testcases--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << solution.longest_sub_sequence(s1, s2) << endl;
    }
}