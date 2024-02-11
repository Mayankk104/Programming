// Minimum swaps and K together: https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
// Tags: #easy #scaler #M4DSA1 #array2 #additional
// Time Complexity: O(n) | Space Complexity: O(1)
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int swaps(vector<int>& arr, int target) {
        int window_size = 0, valid_num_in_window = 0, max_valid_num_in_window = 0;

        for (auto num : arr)
            if (num <= target) window_size++;

        for (int i = 0; i < window_size; i++)
            if (arr[i] <= target) valid_num_in_window++;

        if (max_valid_num_in_window < valid_num_in_window) max_valid_num_in_window = valid_num_in_window;

        for (int i = 0; i < arr.size() - window_size; i++) {
            if (arr[i] <= target && arr[i + window_size] > target) valid_num_in_window--;
            if (arr[i] > target && arr[i + window_size] <= target) valid_num_in_window++;

            if (max_valid_num_in_window < valid_num_in_window) max_valid_num_in_window = valid_num_in_window;
        }

        return window_size - max_valid_num_in_window;
    }
};

int main() {
    Solution solution;
    vector<int> input = {1, 12, 10, 3, 14, 10, 5};

    cout << solution.swaps(input, 8);
}