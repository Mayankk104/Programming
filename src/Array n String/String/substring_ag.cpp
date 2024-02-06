// Special Subsequences "AG"
// Tags: #easy #scaler #M4DSA1 #array2 #additional
// Efficiency: Time Complexity O(n), Space Complexity O(n)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int sub_string_ag(string str) {
        int size = str.size(), sum = 0;
        vector<int> prefix_sum(size + 1, 0);

        for (int i = size - 1; i >= 0; i--)
            prefix_sum[i] = str[i] == 'G' ? prefix_sum[i + 1] + 1 : prefix_sum[i + 1];

        for (int i = 0; i < size; i++)
            if (str[i] == 'A') {
                sum += prefix_sum[i];
                sum %= 1000000007;
            }

        return sum;
    }
};

int main() {
    Solution solution;

    cout << solution.sub_string_ag("ABCGAG");
}