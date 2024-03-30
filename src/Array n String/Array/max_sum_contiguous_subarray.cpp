// Tags: #easy #scaler #M4DSA1 #array1 #assignment #kadane's algorithm
// Time Complexity: O(n) | Space Complexity: O(1)

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int max_sum(const vector<int>& arr) {
        int max_sum = INT_MIN, sum = 0;

        for (int num : arr) {
            sum += num;
            max_sum = max(sum, max_sum);
            if (sum < 0) sum = 0;
        }

        return max_sum;
    }
};

int main() {
    Solution solution;
    cout << "maximun contiguous sum: " << solution.max_sum({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
}