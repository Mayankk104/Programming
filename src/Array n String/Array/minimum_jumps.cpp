#include <iostream>
#include <vector>
// TODO: complete it
using namespace std;

class Solution {
   public:
    int minimum_jumps(vector<int> arr) {
        int position = 0, jumps = 0;

        while (position < arr.size()) {
            int furthest = position;
            // cout << position << " " << furthest << endl;

            for (int i = position; i < position + arr[position]; i++) {
                cout << position + arr[i] << " ";
                if (position + arr[i] > arr.size()) return jumps++;
                if ((arr[i] + position) > furthest) furthest = arr[i] + position;
            }
            cout << endl;

            position = furthest;
            jumps++;
        }
        return 0;
    }
};

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Solution solution;

    cout << solution.minimum_jumps(input);
}