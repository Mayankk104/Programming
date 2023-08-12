// 724. Find Pivot Index: https://leetcode.com/problems/find-pivot-index/
// Tags: #easy
// Efficiency: Time Complexity O(n), Space Complexity O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int pivotIndex(vector<int> &nums) {
        int arrSize = nums.size();
        int leftSum = 0, rightSum = 0;

        for (int num : nums) {
            rightSum += num;
        }

        for (int i = 0; i < arrSize; i++) {
            rightSum -= nums[i];

            if (rightSum == leftSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> array = {7, 3, 1, 6, 5, 6};

    cout << solution.pivotIndex(array);
}