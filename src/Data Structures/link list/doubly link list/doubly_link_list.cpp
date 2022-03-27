#include "./headers/doubly_link_list.h"


template<typename T> DoublyLinkList<T>::DoublyLinkList(){
    head = NULL;
    size=0;
}

template<typename T> void DoublyLinkList<T>::insert_at_end(T value){
    Node<T> *node = new Node<T>(value);
    size++;

    if(head == NULL){
        head = node;
        return;
    }

    Node<T> *temp=head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->next = node;
    node->previous = temp;
}

template<typename T> void DoublyLinkList<T>::insert_at_begging(T value){
    Node<T> *node = new Node<T>(value);
    size++;

    node->next=head;
    head=node;
    if(size>1)
        node->next->previous = node;
}

template<typename T> bool DoublyLinkList<T>::insert_at_postion(T value,int index){
    if(index > size || index<0)
        return false;


    if(index == size){
        insert_at_end(value);
        size++;
        return true;
    }

    size++;

    if(index == 0){
        insert_at_begging(value);
        return true;
    }

    Node<T> *temp = head;

    for(int i=0;i<index;i++)
        temp = temp->next;

    Node<T> *node = new Node<T>(value);

    node->next = temp;
    node->previous = node->next->previous;
    node->previous->next = node;
    node->next->previous = node;
    return true;
}

template<typename T> Node<T>* DoublyLinkList<T>::at_index(int index){
    if(index>size || index<0)
        return NULL;
    
    Node<T> *temp = head;

    for(int i=0;i<index;i++)
        temp = temp->next;
    
    return temp;
}

template<typename T> int DoublyLinkList<T>::search(T value){
    Node<T> *temp = head;
    int index = 0;
    bool isFound = false;

    while(temp!=NULL && !isFound){
        if(temp->data == value)
            isFound = true;
        temp = temp->next;
        index++;
    }
    return isFound ? -1 : index;
}

template<typename T>void DoublyLinkList<T>::display(){
    if(head == NULL){
        cout<<"list is empty :(";
        return;
    }

    Node<T> *temp=head;

    while(temp->next!=NULL){
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<temp->data;
    cout<<"\n";
    while(temp->previous!=NULL){
        cout<<temp->data<<" <-> ";
        temp=temp->previous;
    }
    cout<<temp->data;
}

template<typename T> bool DoublyLinkList<T>::remove_at(int index){
    return true;
}

template<typename T> bool DoublyLinkList<T>::remove(T value){
    return true;
}

template class DoublyLinkList<int>;
template class DoublyLinkList<bool>;
template class DoublyLinkList<char>;
template class DoublyLinkList<long>;
template class DoublyLinkList<float>;
template class DoublyLinkList<double>;
template class DoublyLinkList<string>;