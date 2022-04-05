// leetcode: 20.Valid Parentheses https://leetcode.com/problems/valid-parentheses/submissions/

function isValid(s: string): boolean {
    if (s.length % 2 != 0) return false;
    let stack = [];

    for (let i = 0; i < s.length; i++) {
        switch (s.charAt(i)) {
            case "(":
                stack.push(")");
                break;
            case "[":
                stack.push("]");
                break;
            case "{":
                stack.push("}");
                break;
            default:
                if (s.charAt(i) != stack.pop())
                    return false;
                break;
        }
    }

    return stack.length == 0;
};

console.log(isValid('({)}[]'));