#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> input = {10, 5, 13, 25, 9, 0, 6, 45}, result;
    deque<int> dq;

    int window_size = 3;

    for (int i = 0; i < input.size(); i++) {
        while (!dq.empty() && dq.back() < input[i]) dq.pop_back();

        dq.push_back(input[i]);

        if (i - window_size >= -1) {
            result.push_back(dq.front());
            if (input[i - window_size + 1] == dq.front()) dq.pop_front();
        }
    }

    for (auto x : result) cout << x << " ";
    cout << endl;
};