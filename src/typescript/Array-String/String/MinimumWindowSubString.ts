// leetcode: 76. Minimum Window Substring (https://leetcode.com/problems/minimum-window-substring/) #Blind75

type Hash = { [key: string]: number };

function minWindow(s: string, t: string): string {
    let hash: Hash = {},
        hash2: Hash = {};
    let l = 0,
        r = 0,
        count = 0,
        count2 = 0;

    for (let i = 0; i < t.length; i++) {
        if (!t[i]) hash[t[i]] = 1;
        else hash[t[i]] = hash[t[i]] + 1;

        count++;
    }

    while (r < s.length && l < s.length - t.length + 1) {
        if (!hash2[s[r]] && hash[t[r]]) {
            hash2[s[r]] = 1;
            count2++;
        } else if (hash2[s[r]] && hash[t[r]]) {
            hash2[s[r]] = hash2[s[r]] + 1;
            count2++;
        } else {
            r++;
            continue;
        }
    }

    return t;
}

console.log(minWindow("ADOBECODEBANC", "ABC"));
