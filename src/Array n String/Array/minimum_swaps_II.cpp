#include <iostream>
#include <vector>
// TODO: review and rewrite
using namespace std;

int minSwaps(vector<int>& arr) {
    int n = arr.size();
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        // Check if the current element is at its correct position
        while (arr[i] != i) {
            // Swap the current element with its correct position
            int temp = arr[arr[i]];
            arr[arr[i]] = arr[i];
            arr[i] = temp;
            swaps++;
        }
    }

    return swaps;
}

int main() {
    // Example usage:
    vector<int> arr = {2, 0, 1, 3};
    cout << minSwaps(arr) << endl;  // Output: 1

    return 0;
}
