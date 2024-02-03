// Sub-matrix Sum Queries
// Tags: #medium #scaler #M4DSA1 #array2 #assignment
// Efficiency: Time Complexity O(MxN), Space Complexity O(MXN)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<long long>> prefix_matrix_sum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<long long>> prefix_sum_matrix(rows + 1, vector<long long>(columns + 1, 0));

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                prefix_sum_matrix[i + 1][j + 1] = matrix[i][j];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                prefix_sum_matrix[i + 1][j + 1] = prefix_sum_matrix[i + 1][j] + matrix[i][j];

        for (int j = 0; j < columns; j++)
            for (int i = 0; i < rows; i++)
                prefix_sum_matrix[i + 1][j + 1] = prefix_sum_matrix[i][j + 1] + prefix_sum_matrix[i + 1][j + 1];

        return prefix_sum_matrix;
    }

   public:
    vector<int> solve(vector<vector<int>>& matrix, vector<int>& B, vector<int>& C, vector<int>& D, vector<int>& E) {
        vector<int> result;
        vector<vector<long long>> prefix_sum_matrix = prefix_matrix_sum(matrix);

        for (int i = 0; i < B.size(); i++) {
            int x1 = B[i], y1 = C[i], x2 = D[i], y2 = E[i];

            long long sum = prefix_sum_matrix[x2][y2] - prefix_sum_matrix[x2][y1 - 1] - prefix_sum_matrix[x1 - 1][y2] + prefix_sum_matrix[x1 - 1][y1 - 1];

            while (sum < 0)
                sum += 1000000007;
            sum = sum % 1000000007;

            result.push_back(sum);
        }

        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> B = {1, 2}, C = {1, 2}, D = {2, 3}, E = {2, 3};
    Solution solution;

    vector<int> result = solution.solve(matrix, B, C, D, E);

    for (int num : result)
        cout << num << " ";
}