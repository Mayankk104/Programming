#pragma once
#include <list>
#include <map>

using namespace std;

class Graph {
    map<int, bool> visited;
    map<int, list<int>> adjecent_list;

   public:
    void dfs(int num);
    void addEdge(int from, int to);
    bool hasConnectingEdge(int from, int to);
};