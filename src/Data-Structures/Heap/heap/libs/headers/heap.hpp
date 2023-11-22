#pragma once
#include <vector>
using namespace std;

class Heap {
   private:
    vector<int> heap;

   public:
    void insert(int t);
    void remove(int n);  // TODO: write implementation

    void show();
};