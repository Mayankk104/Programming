// Time Complexity O(n^2), Space Complexity O(n)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, vector<int> &B) {
    map<pair<int, int>, int> mp;
    int size = A.size(), result = 0;

    for (int i = 0; i < size; i++) mp[{A[i], B[i]}]++;

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (A[i] != A[j] && B[i] != B[j]) {
                if (mp[{A[i], B[j]}] != 0 && mp[{A[j], B[i]}] != 0)
                    result++;
            }
        }
    }
    return result / 2;
}

int main() {
    vector<int> input = {1, 1, 2, 2, 3, 3};
    vector<int> input2 = {1, 2, 1, 2, 1, 2};
    cout << solve(input, input2);

    return 0;
}