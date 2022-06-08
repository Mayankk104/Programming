// leetCode: 45. Jump Game II(https://leetcode.com/problems/jump-game-ii)
// tags: #medium #greedy
// efficiency: Time Complexity O(n), Space Complexity O(1)

function jump(nums: number[]): number {
    let jumps = 0, l = 0, r = 0, furthest;

    while (r < nums.length - 1) {
        furthest = 0;

        for (let i = l; i < r + 1; i++)
            furthest = Math.max(furthest, nums[i] + i);

        l = r + 1;
        r = furthest;
        jumps++;
    }
    return jumps;
};

console.log(jump([2, 3, 1, 1, 4]));