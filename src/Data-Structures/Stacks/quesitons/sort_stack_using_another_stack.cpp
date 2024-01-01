#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A) {
    vector<int> B;
    while (A.size() != 0) {
        int temp = A.back();
        A.pop_back();

        while (B.size() > 0 && B.back() > temp) {
            int back = B.back();
            B.pop_back();
            A.push_back(back);
        }
        B.push_back(temp);
    }
    for (auto x : B) cout << x << " ";
    cout << endl;
    return B;
}
int main() {
    vector<int> input = {5, 4, 3, 2, 1};
    input = solve(input);
}