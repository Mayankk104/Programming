// leetcode: 424. https://leetcode.com/problems/longest-repeating-character-replacement/
function characterReplacement(s: string, k: number): number {
    let l = 0,
        r = 0;
    let alphabets = {};
    let res = 0;
    let maxCount: number;

    while (r < s.length) {
        alphabets[s[r]] = alphabets[s[r]] + 1 || 1;
        maxCount = maxAlphCount(alphabets);

        if (r - l + 1 - maxCount <= k) {
            res = Math.max(r - l + 1, res);
        } else {
            alphabets[s[l]] = alphabets[s[l]] - 1;
            l++;
        }
        r++;
    }

    return res;
}

function maxAlphCount(obj: any) {
    let maxCount: any = 0;
    for (let [a, i] of Object.entries(obj)) if (maxCount < i) maxCount = i;

    return maxCount;
}

characterReplacement("ABAB", 2);
characterReplacement("ABAA", 2);
