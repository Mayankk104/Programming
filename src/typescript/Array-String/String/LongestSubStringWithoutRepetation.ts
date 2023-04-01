// leetcode 3: https://leetcode.com/problems/longest-substring-without-repeating-characters/

function lengthOfLongestSubstring(s: string): number {
    let set = new Set();
    let maxLength = 0;
    let count = 0;
    let l = 0;

    for (let i = 0; i < s.length; i++) {
        if (!set.has(s[i])) {
            set.add(s[i]);
            count++;
        } else {
            while (s[l] !== s[i]) {
                set.delete(s[l]);
                l++;
                count--;
            }
            l++;
        }

        if (count > maxLength) maxLength = count;
    }

    return maxLength;
}

lengthOfLongestSubstring("aabaab!b");
