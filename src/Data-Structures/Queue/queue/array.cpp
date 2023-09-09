#include "./array.hpp"

#include <bits/stdc++.h>
using namespace std;

Queue::Queue(int capcity) {
    this->capcity = abs(capcity);
    arr = new int[abs(capcity)];
}

int Queue::front() {
    if (rear_prt == front_prt && size == 0) {
        cout << "Queue is empty" << endl;
        return 0;
    }
    return arr[(front_prt + 1) % capcity];
}

void Queue::enqueue(int num) {
    if (size == capcity) {
        cout << "Queue is full" << endl;
        return;
    }
    rear_prt = (rear_prt + 1) % capcity;
    arr[rear_prt] = num;
    size++;
    cout << num << " inserted successfully" << endl;
}

int Queue::dequeue() {
    if (size == 0) {
        cout << "Queue is empty" << endl;
        return 0;
    }
    front_prt = (front_prt + 1) % capcity;
    size--;
    cout << arr[front_prt] << " removed successfully" << endl;
    return arr[front_prt];
}