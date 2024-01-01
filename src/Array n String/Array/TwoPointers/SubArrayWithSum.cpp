// #two-pointer
// Time Complexity O(n) Space Complexity O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, int B) {
    int left = 0, right = 0, size = A.size(), sum = A[0];
    vector<int> result;

    while (right < size && left < size) {
        if (sum == B) {
            for (int i = left; i <= right; i++) result.push_back(A[i]);
            return result;
        }

        if (sum > B && left < right) {
            sum -= A[left++];
        } else {
            right++;
            sum += A[right];
        }
    }

    result.push_back(-1);
    return result;
}

int main() {
    vector<int> input = {1, 2, 3, 4, 5};
    solve(input, 5);
}
