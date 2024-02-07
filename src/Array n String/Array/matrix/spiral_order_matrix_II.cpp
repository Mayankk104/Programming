// Spiral Order Matrix II: https://www.interviewbit.com/problems/spiral-order-matrix-ii/
// Tags: #easy #scaler #M4DSA1 #array2 #additional
// Efficiency: Time Complexity O(n*m), Space Complexity O(1)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> spiral_triversal(int n) {
        int count = 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        for (int depth = 0; depth < (n + 1) / 2; depth++) {
            for (int i = depth; i < n - depth; i++)
                matrix[depth][i] = count++;

            for (int i = depth + 1; i < n - depth; i++)
                matrix[i][n - depth - 1] = count++;

            for (int i = depth + 1; i < n - depth; i++)
                matrix[n - depth - 1][n - i - 1] = count++;

            for (int i = depth + 1; i < n - depth - 1; i++)
                matrix[n - i - 1][depth] = count++;
        }

        return matrix;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = solution.spiral_triversal(5);

    for (auto row : matrix) {
        for (auto cell : row)
            cout << cell << " ";
        cout << endl;
    }
}