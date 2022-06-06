function search(nums: number[], target: number): number {
    let l = -1, r = nums.length;
    let m: number;

    while (r - l > 1) {
        m = Math.floor((r - l) / 2) + l;

        if (nums[m] === target)
            return m;

        if (nums[m] > target)
            r = m;
        else
            l = m;

    }

    return -1;
};

console.log(search([1, 4, 7, 8, 9, 11], 11))