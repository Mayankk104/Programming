#pragma once

class Queue {
   private:
    int size = 0, capcity = 0, front_prt = -1, rear_prt = -1;
    int* arr;

   public:
    Queue(int capcity);
    void enqueue(int item);
    int dequeue();
    int front();
};