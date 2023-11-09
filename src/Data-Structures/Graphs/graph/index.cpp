#include <iostream>
#include <vector>

#include "./lib/headers/graph.hpp"

using namespace std;

using namespace std;

int main() {
    vector<vector<int>> input = {
        {1, 2},
        {4, 1},
        {2, 4},
        {3, 4},
        {5, 2},
        {1, 3}};

    Graph graph;

    for (auto edge : input) {
        graph.addEdge(edge[0], edge[1]);
    }

    cout << graph.hasConnectingEdge(1, 5);
}