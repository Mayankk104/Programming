// 76. Minimum Window Substring https://leetcode.com/problems/minimum-window-substring/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
	string minWindow(string s, string t)
	{
		unordered_map<char, int> t_map, s_map;
		int l = 0, r = 0, need = 0, have = 0;
		string res = "";

		for (int i = 0; i < s.length(); i++)
		{
			if (t_map[s[i]])
			{
				t_map[s[i]]++;
			}
			else
			{
				t_map[s[i]] = 1;
				need++;
			}
		}

		while (r < s.length() && l < (s.length() - t.length()))
		{
			if (have >= need)
			{
				l++;
			}
			else
			{
				r++;
				if (t_map[s[r]])
					;
			}
		}

		return res;
	}
};

using namespace std;

int main()
{
	Solution s;
	cout << s.minWindow("Mayanak kumar", "Mayank");
}
