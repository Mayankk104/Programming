// leetcode: 242. Valid Anagram https://leetcode.com/problems/valid-anagram/

function isAnagram(s: string, t: string): boolean {
    const hashmap1 = {};

    for (let char of s)
        if (!hashmap1[char])
            hashmap1[char] = 1
        else
            hashmap1[char] += 1;


    for (let char of t)
        if (!hashmap1[char])
            return false
        else
            hashmap1[char] -= 1;


    for (let val of Object.values(hashmap1))
        if (val !== 0)
            return false

    return true;
};

console.log(isAnagram("anagram", "nagaram"));