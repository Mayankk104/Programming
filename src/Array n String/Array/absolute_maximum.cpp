// Tags: #scaler #medimum #M4DSA1 #array1 #additional
// Efficiency: Time Complexity O(n) | Space Complexity: O(1)

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int solve(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        int result = 0;

        for (int i = 0; i < 32; i++) {
            int combination = i, local_max = INT_MIN, local_min = INT_MAX;
            for (int j = 0; j < A.size(); j++) {
                int a, b, c, d, index, local_combination = combination;

                for (int k = 0; k < 5; k++) {
                    int isSetBit = local_combination & 1;
                    local_combination = local_combination >> 1;

                    if (k == 0) a = isSetBit ? A[j] : A[j] * -1;
                    if (k == 1) b = isSetBit ? B[j] : B[j] * -1;
                    if (k == 2) c = isSetBit ? C[j] : C[j] * -1;
                    if (k == 3) d = isSetBit ? D[j] : D[j] * -1;
                    if (k == 4) index = isSetBit ? j : j * -1;
                }

                local_max = max(local_max, (a + b + c + d + index));
                local_min = min(local_min, (a + b + c + d + index));
            }
            result = max((local_max - local_min), result);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> a = {-27, -7, -48};
    vector<int> b = {-40, -33, -43};
    vector<int> c = {-22, -22, -16};
    vector<int> d = {-22, -5, -2};

    cout << "Maximum of expression |A[i] - A[j]| + |B[i] - B[j]| + |C[i] - C[j]| + |D[i] - D[j]| + |i - j| is : " << solution.solve(a, b, c, d) << endl;
}
