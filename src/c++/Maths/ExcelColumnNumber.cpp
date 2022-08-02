// Excel Column Number (https://www.interviewbit.com/problems/excel-column-number/)
// tags: #easy
// efficiency: Time Complexity O(n), Space Complexity O(1)

#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int titleToNumber(string A)
    {
        int result = 0, l = A.length();

        for (int i = 0; i < l; i++)
            result += (A[i] - 64) * pow(26, l - 1 - i);

        return result;
    }
};

int main()
{
    Solution solution;
    string input = "AAA";

    cout << solution.titleToNumber(input);
}
