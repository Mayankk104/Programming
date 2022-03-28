// leetcode: 647. https://leetcode.com/problems/palindromic-substrings/
function countSubstrings(s: string): number {
    let l: number, r: number, count: number = 0;

    for (let i = 0; i < s.length; i++) {
        l = r = i;
        while (l >= 0 && r < s.length) {
            if (s[l] === s[r]) {
                count++;
                l--;
                r++;
            } else {
                break;
            }
        }
        l = r = i;
        r++;
        while (l >= 0 && r < s.length) {
            if (s[l] === s[r]) {
                count++;
                l--;
                r++;
            } else {
                break;
            }
        }

    }

    return count;
};

console.log(countSubstrings("abababa"));