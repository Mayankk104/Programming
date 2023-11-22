#include "./headers/graph.hpp"

#include <iostream>
#include <list>

using namespace std;

void Graph::addEdge(int from, int to) {
    this->adjecent_list[from].push_back(to);
}

void Graph::dfs(int num) {
    this->visited[num] = true;
    cout << num << "->";

    list<int>::iterator i;

    for (i = this->adjecent_list[num].begin(); i != adjecent_list[num].end(); i++)
        if (!visited[*i]) dfs(*i);

    cout << endl;
}

bool Graph::hasConnectingEdge(int from, int to) {
    if (from == to) return true;

    this->visited[from] = true;
    cout << from << "=>";

    list<int>::iterator i;

    for (i = this->adjecent_list[from].begin(); i != adjecent_list[from].end(); i++)
        if (!visited[*i]) dfs(*i);

    return visited[to];
}