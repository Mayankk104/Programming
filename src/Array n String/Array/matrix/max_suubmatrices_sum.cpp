// Maximum Sum Square SubMatrix: https://www.interviewbit.com/problems/maximum-sum-square-submatrix/
// Tags: #medium #scaler #M4DSA1 #array2 #assignment
// Efficiency: Time Complexity O(MxN), Space Complexity O(MXN)

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<long long>> prefix_sum_matrix(vector<vector<int>>& matrix) {
        vector<vector<long long>> prefix_sum_matrix(matrix.size() + 1, vector<long long>(matrix[0].size() + 1, 0));

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                prefix_sum_matrix[i + 1][j + 1] = prefix_sum_matrix[i + 1][j] + matrix[i][j];

        for (int j = 0; j < matrix[0].size(); j++)
            for (int i = 0; i < matrix.size(); i++)
                prefix_sum_matrix[i + 1][j + 1] = prefix_sum_matrix[i][j + 1] + prefix_sum_matrix[i + 1][j + 1];

        return prefix_sum_matrix;
    }

   public:
    int max_submrtices_sum(vector<vector<int>>& matrix, int sub_matrix_size) {
        int max_sum = INT_MIN, rows = matrix.size(), columns = matrix[0].size();

        if (sub_matrix_size > rows || sub_matrix_size > columns)
            return -1;

        vector<vector<long long>> prefix_sum_matrix = this->prefix_sum_matrix(matrix);

        for (int i = 0; i <= rows - sub_matrix_size; i++) {
            for (int j = 0; j <= columns - sub_matrix_size; j++) {
                int bottom_right = prefix_sum_matrix[i + sub_matrix_size][j + sub_matrix_size];
                int top_right = prefix_sum_matrix[i][j + sub_matrix_size];
                int bottom_left = prefix_sum_matrix[i + sub_matrix_size][j];
                int top_left = prefix_sum_matrix[i][j];

                int sum = bottom_right - top_right - bottom_left + top_left;

                max_sum = max(sum, max_sum);
            }
        }

        return max_sum;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> input = {{1, 2, 3}, {3, 2, 1}, {2, 1, 3}};

    cout << solution.max_submrtices_sum(input, 2);
}