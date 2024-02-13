// Rain Water Trapped: https://www.interviewbit.com/problems/rain-water-trapped/, https://leetcode.com/problems/trapping-rain-water/
// Tags: #hard #scaler #M4DSA1 #array3 #assingment
// Time Complexity: O(n) | Space Complexity: O(n)
// NOTE: there is a further optimal solution with O(1) space

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int traped_water(vector<int>& elevations) {
        int size = elevations.size(), traped_water = 0;
        vector<int> prefix(size, 0), suffix(size, 0);

        for (int i = 1; i < size; i++) {
            prefix[i] = max(prefix[i - 1], elevations[i - 1]);
            suffix[size - i - 1] = max(suffix[size - i], elevations[size - i]);
        }

        for (int i = 0; i < size; i++)
            traped_water += max(min(prefix[i], suffix[i]) - elevations[i], 0);

        return traped_water;
    }
};

int main() {
    Solution solution;
    vector<int> input = {0, 1, 0, 2};
    cout << solution.traped_water(input) << endl;
}