#include "./headers/heap.hpp"

#include <iostream>

using namespace std;

void Heap::insert(int num) {
    int size = this->heap.size();
    int parent = size;

    this->heap.push_back(num);

    // heapify time complexity O(log2 n)
    while (parent > 0 && heap[((parent - 1) / 2)] > heap[parent]) {
        swap(heap[((parent - 1) / 2)], heap[parent]);
        parent = (parent - 1) / 2;
    }
}

void Heap::show() {
    cout << endl
         << "Heap : ";
    for (auto num : this->heap) {
        cout << num << " ";
    }
    cout << endl;
}