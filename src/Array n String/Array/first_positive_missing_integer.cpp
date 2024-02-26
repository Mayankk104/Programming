#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int first_missing_positive_missing_number(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            int ci = arr[i] - 1;

            while (arr[i] > 0 && arr[i] <= arr.size() && arr[i] != arr[ci]) {
                swap(arr[i], arr[ci]);
                ci = arr[i] - 1;
            }
        }

        for (int i = 0; i < arr.size(); i++)
            if (arr[i] != i + 1) return i + 1;

        return arr.size() + 1;
    }
};

int main() {
    Solution solution;
    vector<int> input = {0, -10, 1, 3, -20};

    cout << "first missing positive integer: " << solution.first_missing_positive_missing_number(input);
}