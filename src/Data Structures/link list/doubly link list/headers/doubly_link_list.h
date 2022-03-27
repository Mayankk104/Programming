#pragma once
#include "doubly_node.h"
#include<iostream>
using namespace std;

template<typename Type> class DoublyLinkList{
    private:
        int size;
        Node<Type> *head;
    public: 
        DoublyLinkList();

        void insert_at_begging(Type value);
        void insert_at_end(Type value);
        bool insert_at_postion(Type value,int index);

        int search(Type value);
        Node<Type>* at_index(int index);
        void display();

        bool update(Type old_value, Type new_value);
        bool update_at(int index, Type value);

        bool remove(Type value);
        bool remove_at(int index);
};