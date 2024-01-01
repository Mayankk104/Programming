// 15. 3Sum: (https://leetcode.com/problems/3sum)
// Tags: #Blind75 #medium #two-pointer #array
// Efficiency: Time Complexity O(n^2), Space Complexity O(1)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        int l, r, sum, size = nums.size();

        sort(nums.begin(), nums.end());

        if (size < 3 || nums[0] > 0)
            return result;

        for (int i = 0; i < size; i++) {
            if (i > 0 and nums[i] == nums[i - 1])
                continue;

            l = i + 1;
            r = size - 1;

            while (l < r) {
                sum = nums[l] + nums[r] + nums[i];

                if (sum > 0)
                    r--;
                else if (sum < 0)
                    l++;
                else {
                    vector<int> triplate = {nums[i], nums[l], nums[r]};
                    result.push_back(triplate);

                    while (nums[l] == nums[l + 1] and l + 1 < r)
                        l++;

                    l++;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    Solution solution;

    vector<vector<int>> output = solution.threeSum(input);

    for (auto row : output) {
        for (auto element : row)
            cout << element << " ";
        cout << endl;
    }
}
