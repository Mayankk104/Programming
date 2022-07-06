// 509. Fibonacci Number: https://leetcode.com/problems/fibonacci-number
// Tags: #easy #DP
// Efficiency: Time Complexity O(n), Space Complexity O(n)
#include <iostream>
#include <vector>
using namespace std;

class Solution
{

    int helper(int n, vector<int> &fibs)
    {
        if (n < 2)
        {
            fibs[n] = n;
            return fibs[n];
        }

        if (fibs[n] != 0)
        {
            return fibs[n];
        }

        fibs[n] = helper(n - 1, fibs) + helper(n - 2, fibs);

        return fibs[n];
    }

public:
    int fibbonacci(int n)
    {
        vector<int> fibs(n + 1, 0);

        return helper(n, fibs);
    }

    int fibbonacci2(int n)
    {
        if (n < 2)
            return n;

        int num1 = 0;
        int num2 = 1;
        int num3;

        for (int i = 2; i <= n; i++)
        {
            num3 = num1 + num2;
            num1 = num2;
            num2 = num3;
        }
        return num3;
    }
};

int main()
{
    Solution soliton;

    cout << soliton.fibbonacci(8) << endl;
    cout << soliton.fibbonacci2(8) << endl;
}