/*  RUN COMMANDS 

    g++ singly_node.cpp singly_link_list.cpp link_list.cpp -o main.out     if you use linux or mac
    ./main.out

    g++ singly_node.cpp singly_link_list.cpp link_list.cpp -o main.exe     if you use windows
    main.exe 

    respectively

*/


#include<bits/stdc++.h>
#include<conio.h>
#include"./headers/singly_link_list.h"
using namespace std;

void take_user_input(int &choice);
void insert(int choice, LinkList &l);

int main(){
    LinkList l;
    int choice=0, value,index,previous,i;
    char temp;
    bool is_successful;

    
    while(choice!= 10){
        take_user_input(choice);
        switch (choice){
        case 1:
            insert(choice,l);
            break;
        case 2:
            insert(choice,l);
            break;
        case 3:
            insert(choice,l);
            break;
        case 4:
            cout<<"Enter value to be updated: ";
            cin>>previous;
            cout<<"Enter value udated to: ";
            cin>>value;
            is_successful = l.update(previous,value);
            if(!is_successful)
                cout<<"No such value found";
            else
                cout<<"Updated successfully, Press ENTER to continue";
            getch();
            break;
        case 5:
            cout<<"Enter Index: ";
            cin>>index;
            cout<<"Enter Value: ";
            cin>>value;
            is_successful = l.udapte_at_index(value,index);

            if(is_successful)
                cout<<"Update successfully, Press Enter to continue";
            else
                cout<<"Index out of bound";

            getch();
            break;
        case 6:
            cout<<"Enter value to be removed: ";
            cin>> value;
            is_successful= l.remove(value);
            if(!is_successful)
                cout<<"No such value found";
            else
                cout<<"Removed successfully, Press ENTER to continue";
            getch();
            break;
        case 7:
            cout<<"Enter Index: ";
            cin>>index;
            is_successful = l.remove_at(index);
            if(!is_successful)
                cout<<"Index out of bound";
            else
                cout<<"Removed successfully, Press ENTER to continue";
            getch();
            break;
        case 8:
            cout<<"Enter value: ";
            cin>>value;
            i = l.search(value);
            if(i==-1)
                cout<<"Value not found";
            else
                cout<<"Value found at "<<i;
            getch();
            break;
        case 9:
            cout<< "List: ";
            l.display();
            cout<<"\nPress ENTER to conutine.";
            getch();
            break;
        case 10:
            cout<<"Thank you :) Bye";
            break;
        default:
            cout<<"Enter correct option.";
            cin>>choice;
            getch();
            break;
        }
    }
}


void take_user_input(int &choice){
    int c;
    if(system("clear")) system("cls");
    cout<<"Hey!, welcome :) to my link list program choose from following options:\n\n1. insert at beging\n2. insert at index\n3. insert at end\n4. update\n5. update at index\n6. delete\n7. delete at index\n8. search\n9. display\n10. Exit\n\nChoice: ";
    cin>>c;
    choice = c;
    if(system("clear")) system("cls");

}

void insert(int choice, LinkList &l){
    int value,index;
    bool is_inserted;

    cout<<"Enter value: ";
    cin>>value;
    switch(choice){
        case 1:
            l.insert_at_beging(value);
            break;
        case 2:
            cout<<"Enter Index: ";
            cin>>index;
            is_inserted = l.insert_at_position(value,index);
            if(!is_inserted)
                cout<<"\nIndex out of bound.\n";
            break;
        case 3:
            l.insert_at_end(value);
            break;
           
        default:
            break;
    }
    cout<<"Inseted Successfully, Press ENTER to continue.";
    getch();
}