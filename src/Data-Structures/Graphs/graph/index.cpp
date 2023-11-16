#include <iostream>
#include <vector>

#include "./lib/headers/graph.hpp"
#include "./lib/headers/path_indirected_graph.hpp"

using namespace std;

int main() {
    PathInDirectedGraph path_in_directed_graph;
    cout << path_in_directed_graph.solve(5) << endl;
}