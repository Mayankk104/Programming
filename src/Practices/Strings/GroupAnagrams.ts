// leetcode: 49. Group Anagrams https://leetcode.com/problems/group-anagrams/

function groupAnagrams(strs: string[]): string[][] {
    let tempStr: string;
    let hash: { [key: string]: string[] } = {};

    for (let i = 0; i < strs.length; i++) {
        tempStr = strs[i].split('').sort().join('');

        if (!hash[tempStr])
            hash[tempStr] = [strs[i]];
        else
            hash[tempStr].push(strs[i]);
    }

    return Object.values(hash);
};

console.log(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]));