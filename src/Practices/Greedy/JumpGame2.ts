// LeetCode: https://leetcode.com/problems/jump-game-ii/

function jump(nums: number[]): number {
    let jump = 0;
    let l = 0, r = 0;
    let furthest;

    while (r < nums.length - 1) {
        furthest = 0;
        for (let i = l; i < r + 1; i++) {
            if (furthest < nums[i] + i)
                furthest = nums[i] + i;
        }

        l = r + 1;
        r = furthest;
        console.log(l, r);
        jump++;
    }
    return jump;
};

console.log(jump([2, 3, 1, 1, 4]));