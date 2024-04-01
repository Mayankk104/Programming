// 31. Next Permutation: https://leetcode.com/problems/next-permutation/description/
// Tags: #medium #scaler #M4DSA1 #array3 #additional
// Efficiency: Time Complexity O(N log N), Space Complexity O(1)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void next_permutation(vector<int>& arr) {
        int index = -1;

        for (int i = arr.size() - 1; i > 0; i--)
            if (arr[i] > arr[i - 1]) {
                index = i - 1;
                break;
            }

        if (index != -1) {
            for (int i = arr.size() - 1; i >= 0; i--)
                if (arr[i] > arr[index]) {
                    swap(arr[index], arr[i]);
                    break;
                }
        }

        sort(arr.begin() + index + 1, arr.end());
    }
};

int main() {
    Solution solution;
    vector<int> input = {1, 2, 3};
    solution.next_permutation(input);

    cout << "next permutation: ";
    for (int num : input) cout << num << " ";
}