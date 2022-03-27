#pragma once
#include<iostream>
using namespace std;

template<typename X>class Node{
    public:
        X data;
        Node<X> *next,*previous;

        Node(X value);
};
