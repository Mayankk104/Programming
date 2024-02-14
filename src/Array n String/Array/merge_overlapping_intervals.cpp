// Merge Intervals: https://leetcode.com/problems/merge-intervals/description/
// Tags: #medium #scaler #M4DSA1 #array2 #assingment #leetcode
// Time Complexity: O(n log n) | Space Complexity: O(1)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct decreasing {
    inline bool operator()(const vector<int>& interval1, const vector<int>& interval2) {
        return interval1[0] < interval2[0];
    }
};

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int intervals_size = intervals.size();
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end(), decreasing());

        result.push_back(intervals[0]);

        for (int i = 1; i < intervals_size; i++)
            if (result[result.size() - 1][1] >= intervals[i][0])
                result[result.size() - 1][1] = max(result[result.size() - 1][1], intervals[i][1]);
            else
                result.push_back(intervals[i]);

        return result;
    };
};

int main() {
    vector<vector<int>> input = {{2, 6}, {1, 3}, {8, 10}, {15, 18}};
    Solution solution;

    vector<vector<int>> merged_intervals = solution.merge(input);

    for (vector<int> interval : merged_intervals) {
        cout << interval[0] << " " << interval[1] << " -> ";
    }
}