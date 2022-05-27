// 15. 3Sum https://leetcode.com/submissions/detail/694958960/ #Blind75

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		vector<vector<int>> res;
		int l, r, sum;
		int n = nums.size();

		sort(nums.begin(), nums.end());

		if (n < 3 || nums[0] > 0)
			return res;

		for (int i = 0; i < n; i++)
		{
			if (i > 0 and nums[i] == nums[i - 1])
				continue;

			l = i + 1;
			r = n - 1;

			while (l < r)
			{
				sum = nums[l] + nums[r] + nums[i];

				if (sum > 0)
					r--;
				else if (sum < 0)
					l++;
				else
				{
					vector<int> r1;
					r1.push_back(nums[i]);
					r1.push_back(nums[l]);
					r1.push_back(nums[r]);
					res.push_back(r1);

					while (nums[l] == nums[l + 1] and l + 1 < r)
					{
						l++;
					}

					l++;
				}
			}
		}
		return res;
	}
};

int main()
{
	vector<int> v = {0, 0, 0, 0};
	Solution s;

	vector<vector<int>> v2 = s.threeSum(v);

	for (auto v3 : v2)
	{
		for (auto v4 : v3)
		{
			cout << v4 << " ";
		}
		cout << endl;
	}
}
