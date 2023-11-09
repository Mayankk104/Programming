#include <bits/stdc++.h>
using namespace std;

class Graph {
    map<int, bool> visited;
    map<int, list<int>> adjecent_list;

   public:
    void dfs(int num) {
        visited[num] = true;
        list<int>::iterator i;

        for (i = adjecent_list[num].begin(); i != adjecent_list[num].end(); i++)
            if (!visited[*i]) dfs(*i);
    };

    void addEdge(int from, int to) {
        adjecent_list[from].push_back(to);
    };

    bool hasConnectingEdge(int from, int to) {
        if (from == to) return true;
        visited[from] = true;
        list<int>::iterator i;

        for (i = adjecent_list[from].begin(); i != adjecent_list[from].end(); i++)
            if (!visited[*i]) dfs(*i);

        return visited[to];
    };
};

class Solution {
    int solve(int A, vector<vector<int>> &B);
};

int Solution::solve(int A, vector<vector<int>> &B) {
    Graph graph;

    for (int i = 0; i < B.size(); i++) {
        graph.addEdge(B[i][0], B[i][1]);
    }
    return graph.hasConnectingEdge(1, A) ? 1 : 0;
}
