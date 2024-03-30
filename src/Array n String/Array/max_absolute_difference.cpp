// Tags: #medium #scaler #M4DSA1 #array1 #assignment
// Efficiency: Time Complexity: O(n) | Space Complexity: O(1);

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * return maximum value of function f(i,j)
     * f(i,j) = |arr[i] - arr[j]| + |i-j|
     */
    int maximum_absolute_difference(vector<int> arr) {
        int aii = INT_MIN, ajj = INT_MAX, ai_i = INT_MIN, aj_j = INT_MAX;

        for (int m = 0; m < arr.size(); m++) {
            aii = max(aii, arr[m] + m);    //   (A[i] + i) ⬆ maximize
            ajj = min(ajj, arr[m] + m);    //   (A[j] + j) ⬇ minimize
            ai_i = max(ai_i, arr[m] - m);  // (A[i] - i) ⬆ maximize
            aj_j = min(aj_j, arr[m] - m);  // (A[i] - i) ⬇ minimize
        }

        int max1 = aii - ajj;    //   (A[i] + i)⬆ - (A[j] + j)⬇  or -(A[i] + i)⬇ - (A[j] + j)⬆, both expression are equivalent
        int max2 = ai_i - aj_j;  // (A[i] - i)⬆ - (A[j] - j)⬇  or -(A[i] - i)⬇ + (A[j] - j)⬆, both expression are equivalent

        return max(max1, max2);
    }
};

int main() {
    Solution solution;
    cout << "max of |arr[i] - arr[j]| + |i-j|: " << solution.maximum_absolute_difference({1, 3, -1}) << endl;
}