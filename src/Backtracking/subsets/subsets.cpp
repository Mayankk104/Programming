#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void recursion(vector<int>& sub_arr, vector<int>& subset_arr, vector<vector<int>>& result) {
        // for (int num : sub_arr) cout << num << " ";
        // cout << endl
        //      << "-----1-----";

        // for (int num : subset_arr) cout << num << " ";
        // cout << endl
        //      << "-----2-----";

        if (subset_arr.size() == 0) {
            vector<int> _sub_arr;
            for (int num : sub_arr) _sub_arr.push_back(num);
            result.push_back(_sub_arr);
            return;
        }

        for (int i = 0; i < subset_arr.size(); i++) {
            int num = subset_arr[i];

            subset_arr.erase(subset_arr.begin() + i);
            recursion(sub_arr, subset_arr, result);

            sub_arr.push_back(num);

            recursion(sub_arr, subset_arr, result);
            subset_arr.insert(subset_arr.begin() + i, num);

            sub_arr.pop_back();
        }

        // cout << "--------------------end--------------------------";
    }

   public:
    vector<vector<int>> solution(vector<int>& nums) {
        vector<int> sub_nums;
        vector<vector<int>> result;
        recursion(sub_nums, nums, result);

        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    Solution solution;

    result = solution.solution(nums);

    cout << endl;

    for (vector<int> row : result) {
        if (row.size() == 0) {
            cout << "empty array" << endl;
            continue;
        }
        for (int num : row) cout << " " << num;
        cout << endl;
    }
}