// leetcode: 33. Search in Rotated Sorted Array (https://leetcode.com/problems/search-in-rotated-sorted-array/)
// tags: #binary-search #medium #binary-search #scaler #M5DS2
// efficiency: Time Complecity O(log n), Space Complexity O(1)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int roated_binary_search(vector<int> arr, int target) {
        int left = 0, right = arr.size() - 1, middle;

        while (left <= right) {
            middle = left + ((right - left) / 2);

            if (arr[middle] == target) return middle;

            if (arr[left] <= arr[middle]) {
                // left porition is sorted
                if (arr[left] <= target && arr[middle] >= target) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else {
                // right porition is sorted
                if (arr[middle] <= target && arr[right] >= target) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> input = {180, 181, 182, 183, 184, 187, 188, 189, 191, 192, 193, 194, 195, 196, 201, 202, 203, 204, 3, 4, 5, 6, 7, 8, 9, 10, 14, 16, 17, 18, 19, 23, 26, 27, 28, 29, 32, 33, 36, 37, 38, 39, 41, 42, 43, 45, 48, 51, 52, 53, 54, 56, 62, 63, 64, 67, 69, 72, 73, 75, 77, 78, 79, 83, 85, 87, 90, 91, 92, 93, 96, 98, 99, 101, 102, 104, 105, 106, 107, 108, 109, 111, 113, 115, 116, 118, 119, 120, 122, 123, 124, 126, 127, 129, 130, 135, 137, 138, 139, 143, 144, 145, 147, 149, 152, 155, 156, 160, 162, 163, 164, 166, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177};

    cout << solution.roated_binary_search(input, 75) << " ";
}