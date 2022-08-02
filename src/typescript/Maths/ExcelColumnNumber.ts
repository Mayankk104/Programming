// Excel Column Number (https://www.interviewbit.com/problems/excel-column-number/)
// tags: #easy
// efficiency: Time Complexity O(n), Space Complexity O(1)


function titleToNumber(A: string): number {
    let result = 0, l = A.length;

    for (let i = 0; i < l; i++)
        result += (A.charCodeAt(i) - 64) * (26 ** (l - 1 - i));

    return result;
}

const output = titleToNumber("AAA");

console.log(output);