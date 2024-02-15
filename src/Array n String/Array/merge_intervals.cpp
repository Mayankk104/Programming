#include <iostream>
#include <vector>
// TODO: Try Again
using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>> &intervals, vector<int> new_interval) {
        vector<vector<int>> result = {intervals[0]};

        for (int i = 1; i < intervals.size(); i++) {
            if (result[result.size() - 1][1] < new_interval[0]) {
                result[result.size() - 1][0] = min(result[result.size() - 1][0], new_interval[0]);
                result[result.size() - 1][1] = max(result[result.size() - 1][1], new_interval[1]);
            }

            if (result[result.size() - 1][1] < intervals[i][0]) {
                result[result.size() - 1][0] = min(result[result.size() - 1][0], intervals[i][0]);
                result[result.size() - 1][1] = max(result[result.size() - 1][1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> input = {{1, 3}, {6, 9}};
    vector<int> new_interval = {2, 5};

    vector<vector<int>> result = solution.merge(input, new_interval);

    for (vector<int> interval : result)
        cout << interval[0] << " " << interval[1] << " -> ";
}
