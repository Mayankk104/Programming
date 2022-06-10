// leetcode: 3. Longest Substring Without Repeating Characters(https://leetcode.com/problems/longest-substring-without-repeating-characters)
// tags: #sliding-window #string #medium
// efficiency: Time Complexity O(n), Space Complexity O(n)

#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> hashMap;
        int left = 0, right = 0, stringLength = s.length(), result = 0;

        while (right < stringLength)
        {
            if (hashMap[s[right]] == 0)
            {
                result = max(result, (int)s.substr(left, right - left + 1).length());

                hashMap[s[right]]++;
                right++;
            }
            else
            {
                hashMap[s[left]]--;
                left++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb");
}