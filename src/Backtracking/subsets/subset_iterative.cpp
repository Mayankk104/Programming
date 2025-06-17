// 78. Subsets https://leetcode.com/problems/subsets/description/
// Tags: #easy
// Efficiency: Time Complexity O(n * 2^n), Space Complexity O(n * 2^n)
// Idea is to take arr[i] and append it already generated subsets

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> generate_subsets(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};

        for (int i = 0; i < nums.size(); i++) {
            int total_subset_till_now = subsets.size();

            for (int j = 0; j < total_subset_till_now; j++) {
                vector<int> subset = subsets[j];
                subset.push_back(nums[i]);
                subsets.push_back(subset);
            }
        }

        return subsets;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("./subset_input.txt", "r", stdin);
    freopen("./subset_output.txt", "w", stdout);
#endif

    Solution soluion;
    int no_of_test_cases, array_size, num;

    cin >> no_of_test_cases;

    while (no_of_test_cases--) {
        vector<int> input_array;

        cin >> array_size;

        for (int i = 0; i < array_size; i++) {
            cin >> num;
            input_array.push_back(num);
        }

        vector<vector<int>> subsets = soluion.generate_subsets(input_array);

        for (vector<int> subset : subsets) {
            cout << "{ ";
            for (int num : subset) cout << num << " ";
            cout << "}" << endl;
        }

        cout << endl;
    }
}