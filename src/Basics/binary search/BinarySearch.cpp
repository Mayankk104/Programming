// leetcode: 704. Binary Search(https://leetcode.com/problems/binary-search/)
// tags: #binary-search #basic
// efficiency: Time Complecity O(log n), Space Complexity O(1)

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1, middle;

    while (right >= left) {
        middle = left + ((right - left) / 2);

        if (numbers[middle] == target) return middle;

        if (numbers[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
}

int main() {
    vector<int> numbers = {10, 20};
    cout << binarySearch(numbers, 20) << endl;
}