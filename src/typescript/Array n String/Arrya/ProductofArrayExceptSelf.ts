//leetcode: 238. Product of Array Except Self https://leetcode.com/problems/product-of-array-except-self/

function productExceptSelf(nums: number[]): number[] {
    let res = [1];
    let prev: number = 1;

    for (let i = 1; i < nums.length; i++) {
        res.push(res[i - 1] * nums[i - 1]);
    }

    for (let i = nums.length - 2; i > -1; i--) {
        prev *= nums[i + 1];
        res[i] = res[i] * prev;
    }

    return res;
};

console.log(productExceptSelf([-1, 1, 0, -3, 3]));