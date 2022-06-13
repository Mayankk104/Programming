// 120. Triangle (https://leetcode.com/problems/triangle/)
// tags: #medium #DP
// efficiency: time complexity O(n), space complexity O(n^1/2)

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<int> row;
        int ptr = triangle.size() - 1;

        row.assign(triangle[ptr].begin(), triangle[ptr].end());

        while (ptr > 0)
        {
            for (int i = 0; i <= ptr - 1; i++)
                row[i] = triangle[ptr - 1][i] + min(row[i], row[i + 1]);
            ptr--;
        }

        return row[0];
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> input = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    int output = solution.minimumTotal(input);

    cout << output;
}