// Filp https://www.interviewbit.com/problems/flip/
// Tags: #easy #scaler #M4DSA1 #array1 #assignment
// Efficiency: Time Complexity O(N), Space Complexity O(1)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> flip(string str) {
        vector<int> result(2, -1);
        int count = 0, max_count = 0, start_ptr = -1;

        for (int i = 0; i < str.size(); i++) {
            count += str[i] == '1' ? -1 : 1;

            if (count < 0) {
                count = 0;
                start_ptr = i;
            }

            if (count > max_count) {
                result[0] = start_ptr + 2;  // 1 based indexing
                result[1] = i + 1;
                max_count = count;
            }
        }

        if (max_count == 0) return {};

        return result;
    }
};

int main() {
    Solution solution;
    vector<string> inputs = {"11000110001", "111"};

    for (string input : inputs) {
        vector<int> result = solution.flip(input);
        if (result.size() == 0)
            cout << "no filp required";

        if (result.size() != 0)
            for (int item : result)
                cout << item << " ";
        cout << endl;
    }
}