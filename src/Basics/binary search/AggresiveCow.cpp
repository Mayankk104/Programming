//
// Time Complexity: O(n(log max(stall))) Space Comlexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool canDistancePossible(vector<int> stalls, int distance_to_maintain, int number_of_cows) {
    int last_cow_position = stalls[0], placed_cows = 1, stall_size = stalls.size();

    for (int i = 1; i < stall_size; i++) {
        if ((stalls[i] - last_cow_position) >= distance_to_maintain) {
            last_cow_position = stalls[i];
            placed_cows++;
        }

        if (placed_cows >= number_of_cows) return true;
    }
    return false;
}

int solve(vector<int> &stalls, int number_of_cows) {
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[stalls.size() - 1] - stalls[0], mid;
    bool possible = false;

    while (low <= high) {
        mid = low + ((high - low) / 2);
        possible = canDistancePossible(stalls, mid, number_of_cows);
        if (possible) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return high;
}

int main() {
    vector<int> stalls = {1, 2, 3, 4, 5};
    int number_of_cows = 3;

    cout << "maximum minimum distance that can be maintained between " << number_of_cows << " cows is : " << solve(stalls, 3) << endl;
}
