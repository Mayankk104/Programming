#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &A) {
    int n = A.size();
    vector<int> mrsa(n, 0);
    int result = 0;

    mrsa[n - 1] = A[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (A[i] > mrsa[i + 1])
            mrsa[i] = A[i];
        else
            mrsa[i] = mrsa[i + 1];
    }

    for (auto x : mrsa)
        cout << x << " ";
    cout << "\n";

    int max_left;
    for (int i = 1; i < n - 1; i++) {
        for (int j = i - 1; j >= 0; j--) {
            max_left = A[j];
            cout << max_left << " " << A[i] << " ";

            if (max_left < A[i] && max_left < A[j])
                max_left = A[j];
        }
        cout << "\n";

        if (max_left == -1)
            continue;

        if (result < (max_left + A[i] + mrsa[i + 1]))
            result = max_left + A[i] + mrsa[i + 1];
    }
    return result;
}

int main() {
    vector<int> a = {5, 4, 3};
    cout << solve(a);
    return 0;
}