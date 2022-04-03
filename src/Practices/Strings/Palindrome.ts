// leetcode: 125. Valid Palindrome,https://leetcode.com/problems/valid-palindrome/

function isPalindrome(s: string): boolean {
    s = s.toLowerCase();
    let l=0,r=s.length-1;
    while(r>l){
        if(!isValidChar(s[l])) { l++; continue; }
        if(!isValidChar(s[r])) { r--; continue; }
        
        if(s[l]!==s[r])
            return false;
        
        l++;
        r--;
    }
    return true
};

function isValidChar(c: string): boolean{
    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        return true;
    return false;
}

console.log(isPalindrome('A man, a plan, a canal: Panama'));