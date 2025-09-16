#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int solution(vector<int> arr) {
        long combinations = (arr.size() * (arr.size() + 1)) / 2, result = 0;

        for (int i = 0; i < 27; i++) {
            int consecutive_zeros = 0;
            long numbers_with_zero_contribution = 0;

            for (int num : arr) {
                if ((num & 1 << i) == 0) {
                    consecutive_zeros++;
                } else {
                    numbers_with_zero_contribution += (consecutive_zeros * (consecutive_zeros + 1)) / 2;
                    consecutive_zeros = 0;
                }
            }

            numbers_with_zero_contribution += (consecutive_zeros * (consecutive_zeros + 1)) / 2;
            result += (combinations - numbers_with_zero_contribution) * (1 << i);
        }

        return result % 1000000007;
    }
};

int main() {
    Solution solution;
    int testcases = 0, size = 0, num = 0;

#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    cin >> testcases;

    while (testcases--) {
        vector<int> arr;
        cin >> size;

        for (int i = 0; i < size; i++) {
            cin >> num;
            arr.push_back(num);
        }

        int output = solution.solution(arr);
        cout << output << endl;
    }
}