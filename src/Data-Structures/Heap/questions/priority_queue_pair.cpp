#include <iostream>
#include <queue>

using namespace std;

struct PairComparator {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
    }
};

int main() {
    auto compare = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.first > rhs.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, PairComparator> pq;

    pq.push({1, 2});
    pq.push({2, 3});
    pq.push({3, 5});
    pq.push({9, 2});
    pq.push({10, 5});

    cout << pq.top().first << " " << pq.top().second;
}