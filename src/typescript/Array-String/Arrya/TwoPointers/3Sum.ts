// leetcode: 15. 3Sum https://leetcode.com/problems/3sum

function threeSum(nums: number[]): number[][] {
    if (nums.length < 3) return [];

    let triplates: number[][] = [];
    let l: number, r: number, sum: number;

    nums.sort((a, b) => a - b);

    for (let [i, num] of nums.entries()) {
        if (i > 0 && nums[i - 1] === num) continue;

        l = i + 1;
        r = nums.length - 1;

        while (l < r) {
            sum = nums[l] + nums[r] + num;
            if (sum > 0) r--;
            else if (sum < 0) l++;
            else {
                triplates.push([num, nums[l], nums[r]]);
                l++;
                while (nums[l] === nums[l - 1] && l < r) l++;
            }
        }
    }

    return triplates;
}

console.log(threeSum([-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4]));
