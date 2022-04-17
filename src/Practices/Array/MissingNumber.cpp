// leetcode: 268. Missing Number https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int total = (size * (size+1))/2;
                     
         for(auto num: nums)
             total -= num;
         
         return total;
    }
};