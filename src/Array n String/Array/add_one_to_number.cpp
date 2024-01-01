// Tags: #scaler #easy #M4DSA1 #array1 #additional
// Efficiency: Time Complexity: O(n) | Space Complexity: O(1)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> plusOne(vector<int> &A) {
        int start = -1;
        vector<int> result;
        bool shouldAdd = true;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] != 0) {
                start = i;
                break;
            }
        }

        if (start == -1) return {1};

        for (int i = A.size() - 1; i >= start; i--) {
            if (shouldAdd) {
                if (A[i] == 9) {
                    result.push_back(0);
                    if (start == i) result.push_back(1);
                    continue;
                }

                result.push_back(A[i] + 1);
                shouldAdd = false;
                continue;
            } else {
                result.push_back(A[i]);
            }
        }

        // swaping 0 with size-1, 1 with size-2...
        for (int i = 0; i < result.size() / 2; i++) {
            result[i] += result[result.size() - i - 1];
            result[result.size() - i - 1] = result[i] - result[result.size() - i - 1];
            result[i] -= result[result.size() - i - 1];
        }

        return result;
    }
};

int main() {
    vector<int> input = {2, 5, 6, 8, 6, 1, 2, 4, 5};
    Solution solution;
    vector<int> result = solution.plusOne(input);

    for (auto item : result) cout << item << " ";
}