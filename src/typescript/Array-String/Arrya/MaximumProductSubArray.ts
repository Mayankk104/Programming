// leetcode: https://leetcode.com/problems/maximum-product-subarray/submissions/

function maxProduct(nums: number[]): number {
    let res: number = Math.max(...nums);
    let min = 1, max = 1;

    for (let num of nums) {
        if (num == 0) {
            min = 1;
            max = 1;
            continue;
        }

        let temp = max * num
        max = Math.max(num, max * num, min * num);
        min = Math.min(num, temp, min * num);
        res = Math.max(min, max, res);
    }

    return res;
}

console.log(maxProduct([1, 2, 3, 4, 5, 6, 0, 7, 8, 9, 10]));