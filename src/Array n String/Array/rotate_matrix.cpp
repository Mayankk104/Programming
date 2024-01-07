// 48. Rotate Image: https://leetcode.com/problems/rotate-image/description/
// Tags: #easy #scaler #M4DSA1 #array2 #assignment
// Efficiency: Time Complexity O(n^2), Space Complexity O(1)

#include <iostream>
#include <vector>

using namespace std;

class Soltuion {
   public:
    void rotate(vector<vector<int>> matrix) {
        int size = matrix.size();

        for (int i = 0; i < size / 2; i++) {
            for (int j = i; j < size - i - 1; j++) {
                int temp1 = matrix[i][j], temp2 = matrix[j][size - 1 - i], temp3 = matrix[size - 1 - i][size - 1 - j], temp4 = matrix[size - 1 - j][i];

                matrix[i][j] = temp4;
                matrix[j][size - 1 - i] = temp1;
                matrix[size - 1 - i][size - 1 - j] = temp2;
                matrix[size - 1 - j][i] = temp3;
            }
        }

        for (vector<int> row : matrix) {
            for (int item : row) {
                if (item < 10) cout << "0";
                cout << item << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Soltuion solution;
    solution.rotate({{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}});
}