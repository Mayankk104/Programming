#include<bits/stdc++.h>
#include"./headers/doubly_node.h"
#include "./headers/doubly_link_list.h"
using namespace std;

int main(){
    DoublyLinkList<string> dll;

    dll.insert_at_begging("Mayank");
    dll.insert_at_end("Shalu");
    dll.insert_at_begging("Komal");
    dll.insert_at_end("Pankaj");
    dll.insert_at_postion("Chando",4);
    dll.display();
    cout<<"\n"<<dll.at_index(0)->data;
}