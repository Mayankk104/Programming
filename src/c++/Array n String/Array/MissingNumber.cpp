// leetcode: 268. Missing Number https://leetcode.com/problems/missing-number/
// #easy 
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int total = (size * (size+1))/2;
                     
         for(auto num: nums){
            total -= num;
         }
         
         return total;
    }
};

int main() {
    vector<int> input = { 0, 1, 2, 3, 4, 6};
    Solution solution;

    int output =  solution.missingNumber(input);

    cout << output;
}