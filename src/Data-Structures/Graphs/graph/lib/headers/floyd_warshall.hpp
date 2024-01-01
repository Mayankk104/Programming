#include <vector>
using namespace std;

class FloydWarshall {
    vector<vector<int>> graph;

   public:
    FloydWarshall(int size);
    vector<vector<int>> floyd_warshall(vector<vector<int>>& input);
};
