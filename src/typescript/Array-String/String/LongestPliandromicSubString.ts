// leetcode: 5. https://leetcode.com/problems/longest-palindromic-substring/submissions/

function longestPalindrome(s: string): string {
    let l = 0,
        r = 0,
        subStr = "";

    for (let i = 0; i < s.length; i++) {
        l = r = i;

        while (s[l] === s[r] && l >= 0 && r < s.length) {
            if (subStr.length < s.slice(l, r + 1).length) subStr = s.slice(l, r + 1);
            l--;
            r++;
        }
        l = i;
        r = i + 1;
        while (s[l] === s[r] && l >= 0 && r < s.length) {
            if (subStr.length < s.slice(l, r + 1).length) subStr = s.slice(l, r + 1);
            l--;
            r++;
        }
    }

    return subStr;
}

console.log(longestPalindrome("ccd"));
