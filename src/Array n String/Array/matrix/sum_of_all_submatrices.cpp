// Sum of all Submatrices
// Tags: #easy #scaler #M4DSA1 #array2 #assignment
// Efficiency: Time Complexity O(M x N), Space Complexity O(1)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int sum_of_sub_matrcies(vector<vector<int>>& matrix) {
        int num_of_rows = matrix.size(), num_of_col = matrix[0].size(), sum = 0;

        for (int i = 0; i < num_of_rows; i++) {
            for (int j = 0; j < num_of_col; j++) {
                int num = ((i + 1) * (j + 1)) * ((num_of_rows - i) * (num_of_col - j));
                sum += matrix[i][j] * num;
            }
        }
        return sum;
    }
};

int main() {
    vector<vector<int>> input = {{1, 2}, {3, 4}};
    Solution solution;
    cout << solution.sum_of_sub_matrcies(input);
}