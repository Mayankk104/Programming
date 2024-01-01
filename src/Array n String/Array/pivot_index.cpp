// 724. Find Pivot Index: https://leetcode.com/problems/find-pivot-index/
// Tags: #easy #scaler #M4DSA1
// Efficiency: Time Complexity O(n), Space Complexity O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
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

    int equilibrium_index(vector<int>& A) {
        vector<int> prefix_sum(A.size() + 1, 0);

        for (int i = 0; i < A.size(); i++)
            prefix_sum[i + 1] = prefix_sum[i] + A[i];

        for (int i = 1; i < prefix_sum.size(); i++)
            if (prefix_sum[i - 1] == (prefix_sum[prefix_sum.size() - 1] - prefix_sum[i])) return i - 1;

        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> array = {7, 3, 1, 6, 5, 6};

    cout << "equilibrium index: " << solution.pivotIndex(array) << endl;
    cout << "equilibrium index: " << solution.equilibrium_index(array) << endl;
}