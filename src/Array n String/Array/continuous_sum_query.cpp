
// Tags: #easy #array #scaler #M4DS1
// Efficiency: Time Complexity: O(A+B) | Space Complexity: O(1)

#include <iostream>
#include <vector>

using namespace std;

class Soltion {
   public:
    vector<int> solve(int num_of_beggers, vector<vector<int>> const &devotees) {
        vector<int> beggers(num_of_beggers, 0);

        for (auto charity : devotees) {
            beggers[charity[0] - 1] += charity[2];
            if (charity[1] < num_of_beggers)
                beggers[charity[1]] -= charity[2];
        }

        for (int i = 1; i <= beggers.size(); i++)
            beggers[i] += beggers[i - 1];

        return beggers;
    }
};

int main() {
    Soltion solution;
    vector<int> result = solution.solve(5, {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}});

    for (auto money : result)
        cout << money << " ";
}