// TODO: put tags

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> next_permutation(vector<int>& arr) {
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

        return arr;
    }
};

int main() {
    Solution solution;
    vector<int> input = {1, 2, 3};
    vector<int> output = solution.next_permutation(input);

    cout << "next permutation: ";
    for (int num : output) cout << num << " ";
}