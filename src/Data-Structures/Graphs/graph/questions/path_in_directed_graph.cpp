#include <vector>

#include "../lib/headers/graph.hpp"
#include "../lib/headers/path_indirected_graph.hpp"
using namespace std;

bool PathInDirectedGraph::solve(int A) {
    vector<vector<int>> input = {
        {1, 2},
        {4, 1},
        {2, 4},
        {3, 4},
        {5, 2},
        {1, 3}};

    Graph graph;

    for (auto edge : input) graph.addEdge(edge[0], edge[1]);

    return graph.hasConnectingEdge(1, A);
}
