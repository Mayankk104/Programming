// Subarray with given XOR: https://www.interviewbit.com/problems/subarray-with-given-xor/
// Tags: #tuf #medium #prefix_sum #interviewbit
// Efficiency: Time Complexity O(n) | Space Complexity: O(n)

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int subArraysWithSumK(vector<int> arr, int k) {
    int xr = 0, count = 0;
    map<int, int> m = {{0, 1}};

    for (int num : arr) {
        xr ^= num;
        count += m[xr ^ k];
        m[xr]++;
    }

    return count;
}

int main() {
    int num_of_testcases, size, num, k;

#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    cin >> num_of_testcases;

    while (num_of_testcases--) {
        vector<int> arr;
        cin >> k;
        cin >> size;
        for (int i = 0; i < size; i++) {
            cin >> num;
            arr.push_back(num);
        }
        int output = subArraysWithSumK(arr, k);
        cout << output << endl;
    }
}
