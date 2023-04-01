// leetcode: 53. https://leetcode.com/problems/maximum-subarray/

function maxSubArray(nums: number[]): number {
    let maxSum = nums[0],
        currentSum = 0;

    for (let num of nums) {
        if (currentSum < 0) currentSum = 0;
        currentSum += num;
        maxSum = Math.max(maxSum, currentSum);
    }

    return maxSum;
}

console.log(maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]));
