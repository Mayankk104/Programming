// Merge Intervals: https://www.interviewbit.com/problems/merge-intervals/
// Tags: #medium #scaler #M4DSA1 #array2 #assignment
// Efficiency: Time Complexity O(N logN), Space Complexity O(N)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>> &intervals, vector<int> new_interval) {
        intervals.push_back(new_interval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result = {intervals[0]};

        for (int i = 1; i < intervals.size(); i++)
            if (intervals[i][0] > result[result.size() - 1][1])
                result.push_back(intervals[i]);
            else
                result[result.size() - 1][1] = max(result[result.size() - 1][1], intervals[i][1]);

        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> input = {{1, 3}, {6, 9}};
    vector<int> new_interval = {2, 5};

    vector<vector<int>> output = solution.merge(input, new_interval);

    for (vector<int> interval : output)
        cout << interval[0] << " " << interval[1] << " -> ";
}
