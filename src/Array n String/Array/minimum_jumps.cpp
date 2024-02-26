#include <iostream>
#include <vector>

using namespace std;

// NOTE: almost perfect answer passed on leetcode but not on GFG and

class Solution {
   public:
    int minimum_jumps(vector<int> arr) {
        int position = 0, furthest = 0, furthest_index = 0, jumps = 0;

        while (position < arr.size()) {
            if (arr[position] + position >= arr.size() - 1) return ++jumps;
            for (int i = position + 1; i <= arr[position] + position; i++) {
                if (arr[i] + i > furthest) {
                    furthest_index = i;
                    furthest = arr[i] + i;
                }
                if (arr[i] + i >= arr.size() - 1) return jumps + 2;
            }
            position = furthest_index;
            if (arr[furthest_index] == 0) return -1;
            jumps++;
        }

        return jumps;
    }
};

int main() {
    vector<int> input = {3, 6, 6, 10, 6, 1, 3, 1, 10, 1, 1, 10, 1, 7, 7, 2, 3, 1, 2, 4, 5, 8, 7, 2, 6, 8, 6, 7, 5, 4, 10, 4, 8, 10, 8};
    Solution solution;

    int jumps = solution.minimum_jumps(input);

    cout << "minimum jumps: " << jumps;
}