// 41. First Missing Positive: https://leetcode.com/problems/first-missing-positive/description/
// Tags: #hard #scaler #M4DSA1 #array3 #assingment
// Efficiency: Time Complexity: O(n) | Space Complexity: O(1)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int first_missing_positive_missing_number(vector<int>& nums) {
        int size = nums.size();

        for (int i = 0; i < size; i++)
            while (nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i])
                swap(nums[nums[i] - 1], nums[i]);

        for (int i = 0; i < size; i++)
            if (nums[i] != i + 1) return i + 1;

        return size + 1;
    }
};

int main() {
    Solution solution;
    vector<int> input = {3, 4, -1, 1};
    int output = solution.first_missing_positive_missing_number(input);
    cout << "first missing positive integer: " << output;
}