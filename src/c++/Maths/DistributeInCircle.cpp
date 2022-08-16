// Distribute in Circle! (https://www.interviewbit.com/problems/distribute-in-circle)
// Tags: #easy
// Efficiency: Time Complexity O(1), Space Complexity O(1)

#include <iostream>
using namespace std;

class Solution
{
public:
    int solve(int numOfitems, int sizeOfCircle, int startingPosition);
};

int Solution::solve(int numOfitems, int sizeOfCircle, int startingPosition)
{
    return ((numOfitems % sizeOfCircle) + (startingPosition % sizeOfCircle) - 1) % sizeOfCircle;
}

int main()
{
    Solution solution;

    cout << solution.solve(8, 11, 15) << endl;
}
