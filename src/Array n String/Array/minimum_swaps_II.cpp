// Minimum swaps II
// Tags: #easy #scaler #M4DSA1 #array2 #additional
// Time Complexity: O(n) | Space Complexity: O(1)
#include <iostream>
#include <vector>

using namespace std;

int minSwaps(vector<int>& arr) {
    int n = arr.size(), swaps = 0;

    for (int i = 0; i < n; i++) {
        while (arr[i] != i) {
            int temp = arr[arr[i]];
            arr[arr[i]] = arr[i];
            arr[i] = temp;
            swaps++;
        }
    }

    return swaps;
}

int main() {
    vector<int> input = {2, 0, 1, 3};
    cout << minSwaps(input) << endl;

    return 0;
}
