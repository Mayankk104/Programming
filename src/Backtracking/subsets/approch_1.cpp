// 78. Subsets https://leetcode.com/problems/subsets/description/
// Tags: #easy #backtracking
// Efficiency: Time Complexity O(n * 2^n), Space Complexity O(n * 2^n)
// space complexity there will 2^n arrays in result and eaching having ~n size
// time complexity there are 2^n leafs and we have to make n yes or no to reach each leaf node

#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void recursion(vector<int>& original, vector<int>& nums, int index, vector<vector<int>>& result) {
        if (index >= original.size()) return;

        if (index == original.size() - 1) result.push_back(nums);
        recursion(original, nums, index + 1, result);

        nums.push_back(original[index]);
        if (index == original.size() - 1) result.push_back(nums);
        recursion(original, nums, index + 1, result);
        nums.pop_back();
    }

   public:
    vector<vector<int>> get_subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> _nums = {};
        recursion(nums, _nums, 0, result);

        return result;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("./subset_input.txt", "r", stdin);
    freopen("./subset_output.txt", "w", stdout);
#endif

    Solution solution;
    vector<int> nums;
    int test_cases, num, size;

    cin >> test_cases;
    while (test_cases--) {
        cin >> size;
        for (int i = 0; i < size; i++) {
            cin >> num;
            nums.push_back(num);
        }

        vector<vector<int>> subsets = solution.get_subsets(nums);

        for (vector<int> subset : subsets) {
            cout << "{ ";
            for (int num : subset) cout << num << " ";
            cout << "}";
            cout << endl;
        }
    }
}