// LeetCode: https://leetcode.com/problems/reverse-bits/

// helper function
function dec2bin(dec: number) {
    return (dec >>> 0).toString(2);
}

function reverseBits(n: number): number {
    let result = 0;
    let bit;

    for (let i = 0; i < 32; i++) {
        bit = (n >> i) & 1;
        result = result | bit;
        if (i !== 31) result = result << 1;
    }
    return result >>> 0;
}

console.log(reverseBits(0b11111111111111111111111111111101));
