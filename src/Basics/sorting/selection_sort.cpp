#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; i++) {
            int min_num = nums[i], min_i = i;
            for(int j=i; j<nums.size(); j++) {
                cout << "i: " << i << ", j: " << j << endl;
                if(nums[j] < min_num) {
                    min_num = nums[j];
                    min_i = j;
                }
            }
            swap(nums[i], nums[min_i]);
        }

        return nums;
    }
};


int main() {
    Solution solution;
    vector<int> arr = {2,5,1,6,7};

    solution.selectionSort(arr);
    for (int num: arr) cout << num << " ";
}
