// Single Number: https://leetcode.com/problems/single-number/description/
// Tags: #easy #scaler #M4DSA1 #bit-manipulations1 #assignment
// Efficiency: Time Complexity O(N), Space Complexity O(1)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int single_number(vector<int>& nums) {
        int result = 0;
        for (int num : nums) result ^= num;

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> inputs = {3, 5, 2, 1, 2, 1, 3};

    int output = solution.single_number(inputs);

    cout << "number appering only once is: " << output;
}