#include "./libs/headers/heap.hpp"
using namespace std;

int main() {
    Heap h;

    h.insert(12);
    h.insert(15);
    h.insert(8);
    h.insert(10);
    h.insert(9);
    h.insert(7);
    h.insert(5);
    h.insert(11);
    h.insert(13);
    h.insert(15);

    h.show();
}