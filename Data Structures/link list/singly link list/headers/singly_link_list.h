#pragma once
#include "singly_node.h"
#include<bits/stdc++.h>
using namespace std;

class LinkList{
    private:
        Node *head;
        int size;
    public:
        LinkList();
        void display();

        void insert_at_beging(int value);
        void insert_at_end(int value);
        bool insert_at_position(int value,int index);

        int search(int value);
        int at_index(int index);

        bool remove_at(int index);
        bool remove(int value);

        bool update(int previous,int new_value);
        bool udapte_at_index(int value,int index);
};