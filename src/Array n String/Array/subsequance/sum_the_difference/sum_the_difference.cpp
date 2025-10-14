

#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int solve(vector<int>& arr) {
        vector<int> subsequance;
        return recusrion(subsequance, INT_MIN, INT_MAX, arr, 0);
    }

    int recusrion(vector<int>& subsequance, int max_till_now, int min_till_now, vector<int>& nums, int index) {
        int _min = min_till_now, _max = max_till_now;

        if (index == nums.size()) {
            if (subsequance.size() == 0) return 0;
            return max_till_now - min_till_now;
        }

        if (nums[index] > max_till_now) max_till_now = nums[index];
        if (nums[index] < min_till_now) min_till_now = nums[index];

        int total_1 = recusrion(subsequance, _max, _min, nums, index + 1);
        subsequance.push_back(nums[index]);
        int total_2 = recusrion(subsequance, max_till_now, min_till_now, nums, index + 1);
        subsequance.pop_back();
        return (total_1 + total_2) % 1000000007;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    Solution solution;
    int testcases = 0, num, l, output;

    cin >> testcases;
    while (testcases--) {
        vector<int> input;
        cin >> l;
        for (int i = 0; i < l; i++) {
            cin >> num;
            input.push_back(num);
        }
        int output = solution.solve(input);
        cout << output << " ";
    }
}