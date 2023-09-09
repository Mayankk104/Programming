#include <bits/stdc++.h>
using namespace std;

string solve(int A) {
    queue<string> q;
    q.push("1");
    q.push("2");
    string front;

    while (A > 0) {
        front = q.front();
        q.push(front + "1");
        q.push(front + "2");
        q.pop();
        A--;
    }

    string rev = front;
    reverse(rev.begin(), rev.end());
    return front + rev;
}

int main() {
    cout << solve(4) << endl;
}
