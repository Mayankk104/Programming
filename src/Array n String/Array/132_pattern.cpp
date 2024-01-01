// 456. 132 Pattern https://leetcode.com/problems/132-pattern/
#include <bits/stdc++.h>

#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    bool find132pattern(vector<int> &nums) {
        int rightNum = INT_MIN;
        int n = nums.size() - 1;
        stack<int> s;

        for (int i = n; i >= 0; i--) {
            if (nums[i] < rightNum) {
                cout << nums[i] << " " << rightNum << " " << s.top();
                return true;
            }

            while (!s.empty() and s.top() < nums[i]) {
                rightNum = s.top();
                s.pop();
            }

            s.push(nums[i]);
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 0, 1, -4, -1};

    cout << s.find132pattern(v) << endl;
}
