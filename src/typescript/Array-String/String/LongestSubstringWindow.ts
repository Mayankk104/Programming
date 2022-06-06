// 76. Minimum Window Substring https://leetcode.com/problems/minimum-window-substring/
function minWindow(s: string, t: string): string {
    if (t == "")
        return "";

    let tMap: any = {}, sMap: any = {};
    let need: number = 0, have: number = 0, left: number = 0, right: number = 0;
    let res: string = "";

    for (let i = 0; i < t.length; i++) {
        if (tMap[t[i]]) {
            tMap[t[i]]++;
        } else {
            tMap[t[i]] = 1;
            need++;
        }
    }

    while (right <= s.length && left <= (s.length - t.length)) {
        if (have >= need) {
            let t1 = tMap[s[left]];
            if (res.length > s.substring(left, right).length || res.length === 0)
                res = s.substring(left, right);

            if (t1) {
                sMap[s[left]]--;
                if (sMap[s[left]] < t1)
                    have--;
            }
            left++;
        } else {
            let t1 = tMap[s[right]];
            let s1 = sMap[s[right]];

            if (t1 && s1)
                sMap[s[right]]++;
            else if (t1 && !s1)
                sMap[s[right]] = 1;

            if (t1 && t1 === sMap[s[right]])
                have++;

            right++;
        }
    }

    return res;
};

console.log(minWindow("a", "a"));