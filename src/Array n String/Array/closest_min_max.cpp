// Tags: #medium #scaler #M4DSA1 #array1 #additional
// Efficiency: Time Complexity: O(n) | Space Complexity: O(1)

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int cloest_min_max(vector<int>& A) {
        int min_val = INT_MAX, max_val = INT_MIN, min_size = INT_MAX, min_ptr = -1, max_ptr = -1;

        for (int num : A) {
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }

        for (int i = 0; i < A.size(); i++) {
            if (A[i] == min_val) min_ptr = i;
            if (A[i] == max_val) max_ptr = i;

            if (min_ptr != -1 && max_ptr != -1)
                min_size = min(min_size, abs(min_ptr - max_ptr));
        }

        return min_size + 1;
    }
};

int main() {
    Solution solution;
    vector<int> input = {814, 761, 697, 483, 981};

    cout << "closest distance between minimum and maximum values is: " << solution.cloest_min_max(input);
}