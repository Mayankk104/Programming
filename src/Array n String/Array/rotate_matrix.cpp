// TODO: complete

#include <iostream>
#include <vector>

using namespace std;

class Soltuion {
   public:
    void rotate(vector<vector<int>> matrix) {
        int size = matrix.size(), temp1, temp2;

        for (int i = 0; i < size / 2; i++) {
            for (int j = i; j < size / 2; j++) {
                temp1 = matrix[i][j];
                temp2 = matrix[i][size - 1 - j];

                matrix[i][size - 1 - j] = temp1;

                temp1 = temp2;
                temp2 = matrix[size - 1 - i][size - 1 - j];

                matrix[size - 1 - i][size - 1 - j] = temp1;

                temp1 = temp2;
                temp2 = matrix[size - 1 - i][j];

                matrix[i][j] = temp1;
            }
        }

        for (vector<int> row : matrix) {
            for (int item : row) {
                cout << item << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Soltuion solution;

    solution.rotate({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    solution.rotate({{1, 2}, {3, 4}});
}