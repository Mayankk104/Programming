#include "../lib/headers/floyd_warshall.hpp"

#include <climits>
#include <iostream>

FloydWarshall::FloydWarshall(int size) {
    vector<vector<int>> graph(size, vector<int>(size, INT_MAX));
}

vector<vector<int>> FloydWarshall::floyd_warshall(vector<vector<int>>& input) {
    vector<vector<int>> result;
    int size = input.size();

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (input[i][j] == -1) input[i][j] = INT_MAX;

    for (int k = 1; k < size; ++k)
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                if (input[i][k] != INT_MAX && input[k][j] != INT_MAX)
                    input[i][j] = min(input[i][j], input[i][k] + input[k][j]);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (input[i][j] == INT_MAX)
                cout << "♾"
                     << " ";
            else
                cout << input[i][j] << " ";
        }
        cout << endl;
    }

    return result;
}