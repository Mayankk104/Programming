// TODO: Review and revice
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> solve(vector<vector<int>> &matrix, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E);
    vector<vector<long long>> prefix_sum_matrix(vector<vector<int>> &matrix);
};

vector<vector<long long>> Solution::prefix_sum_matrix(vector<vector<int>> &matrix) {
    // int n = A.size(), m = A[0].size();
    // vector<vector<long long>> arr(n + 1, vector<long long>(m + 1, 0));

    // for (int i = 0; i < m; i++)
    //     arr[1][i + 1] = A[0][i];

    // for (int i = 1; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         arr[i + 1][j + 1] = A[i][j] + arr[i][j + 1];
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 1; j < m; j++) {
    //         arr[i + 1][j + 1] += arr[i + 1][j];
    //     }
    // }
    // return arr;

    int n = matrix.size(), m = matrix[0].size();
    vector<vector<long long>> prefix_matrix(n + 1, vector<long long>(m + 1, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            prefix_matrix[i + 1][j + 1] = prefix_matrix[i + 1][j] + matrix[i][j];

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            prefix_matrix[i + 1][j + 1] = prefix_matrix[i][j + 1] + matrix[i][j];

    return prefix_matrix;
}

vector<int> Solution::solve(vector<vector<int>> &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    vector<int> result;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 1; j < A[0].size(); j++) {
            A[i][j] += A[i][j - 1];
        }
    }

    for (int j = 0; j < A[0].size(); j++) {
        for (int i = 1; i < A[0].size(); i++) {
            A[i][j] += A[i - 1][j];
        }
    }

    for (auto row : A) {
        for (auto item : row)
            cout << item << " ";

        cout << endl;
    }

    result.push_back(A[D[0] - 1][D[1] - 1] - A[B[0] - 1][B[0] - 1]);
    result.push_back(A[E[0] - 1][E[1] - 1] - A[C[0] - 1][C[0] - 1]);

    return result;
}

int main() {
    Solution solution;
    vector<vector<int>> input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> B = {1, 2}, C = {1, 2}, D = {2, 3}, E = {2, 3};
    // vector<int> output = solution.solve(input, B, C, D, E);

    vector<vector<long long>> prefix_sum = solution.prefix_sum_matrix(input);

    for (auto row : prefix_sum) {
        for (auto item : row) {
            cout << item << " ";
        }
        cout << endl;
    }
}
