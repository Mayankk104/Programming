// Leetcode: 242. Valid Anagram (https://leetcode.com/problems/valid-anagram/)
// Tags: #easy
// Efficiency: Time Complexity O(n+m), Space Complexity O(1)

function isAnagram(s: string, t: string): boolean {
    const hashmap: { [key: string]: number } = {};

    for (let char of s)
        if (!hashmap[char])
            hashmap[char] = 1
        else
            hashmap[char]++;


    for (let char of t)
        if (!hashmap[char])
            return false
        else
            if (--hashmap[char] < 0)
                return false;


    for (let val of Object.values(hashmap))
        if (val !== 0)
            return false

    return true;
};

console.log(isAnagram("anagram", "nagaram"));