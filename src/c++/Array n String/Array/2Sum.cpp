// 1. Two Sum: https://leetcode.com/problems/two-sum
// Tags: #easy #array
// Efficiency: Time Complexity O(n), Space Complexity O(n)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
	public:
	vector<int> twoSum(vector<int> &nums, int target) {
		unordered_map<int, int> hashMap;
		vector<int> result;

		for (int i = 0; i < nums.size(); i++) {
			if (hashMap.find(target - nums[i]) != hashMap.end()) {
				result = { hashMap[target - nums[i]], i };
				return result;
			}
			hashMap[nums[i]] = i;
		}

		return result;
	}
};

int main() {
	Solution solution;
	vector<int> values = { 2, 7, 11, 15 };
	int target = 26;
	vector<int> output = solution.twoSum(values, target);

	for(auto index: output)
		cout << index << " ";
}
