// 1. Two Sum: https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> m;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m.find(target - nums[i]) != m.end())
			{
				res.push_back(m[target - nums[i]]);
				res.push_back(i);
				return res;
			}
			m[nums[i]] = i;
		}

		return res;
	}
};

int main()
{
	Solution s;
	vector v = {2, 7, 11, 15};
	for (auto val : s.twoSum(v, 26))
		cout << val << endl;
}
