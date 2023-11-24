#pragma once
#include <unordered_map>
#include <vector>

using namespace std;

class Graph {
    unordered_map<int, bool> visited;
    unordered_map<int, vector<int>> adjecent_list;

   public:
    void dfs(int num);
    void addEdge(int from, int to);
    bool hasConnectingEdge(int from, int to);
};