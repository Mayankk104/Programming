#include "./headers/singly_link_list.h"


LinkList::LinkList(){
    head=NULL;
    size=0;
}

void LinkList::display(){
    Node *temp = head;

    if(temp==NULL)
        cout<<"List is empty :(";
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"\n";
}

void LinkList::insert_at_end(int value){
    Node *node = new Node(value);
    Node *temp;
    if(head==NULL){
        head = node;
    }else{
        temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next=node;
    }
    size++;
};

void LinkList::insert_at_beging(int value){
    Node* temp = head;
    Node *node = new Node(value);

    size++;

    if(temp==NULL){
        head = node;
        return;
    }
    node->next = temp;
    head = node;
}

bool LinkList::insert_at_position(int value,int index){
    if(index>size) return false;
    if(index==0) {
        insert_at_beging(value);
        return true;
    }
    
    Node *temp = head;
    Node *node = new Node(value);
    for(int i=0;i<index-1;i++)
        temp = temp->next;
    
    node->next = temp->next;
    temp->next = node;
    size++;
    return true;
}

int LinkList::search(int value){
    int i=0;
    bool found=false;
    Node *temp=head;

    while(temp!=NULL && !found){
        i++;
        if(temp->data==value)
            found=true;
        else
            temp=temp->next;
    }
    return found ? i : -1;
}

int LinkList::at_index(int index){
    if(index>=size) return -1;

    Node *temp = head;

    if(index == 0){
        return temp->data;
    }
    for(int i=0;i<index;i++)
        temp = temp->next;

    return temp->data;
}

bool LinkList::remove(int value){
    Node *temp,*temp2;
    bool found = false;

    if(head==NULL) return false;
    
    temp=head;

    if(temp->data==value){
        head = temp->next;
        delete temp ;
        size--;
        return true;
    }

    while(temp->next!=NULL && !found){
        if(temp->next->data == value)
            found = true;
        else
            temp = temp->next;
    }

    if(found){
        temp2= temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
    return found ? true:false;
}

bool LinkList::remove_at(int index){
    if(index>=size) return false;
    
    Node *temp=head,*temp2;
    size--;
    
    if(index==0){
        head=temp->next;
        delete temp;
        return true; 
    }

    for(int i=0;i<index;i++){
        temp2 = temp;
        temp  = temp->next;
    }

    temp2->next = temp->next;
    delete temp;
    return true;
}

bool LinkList::update(int previous, int new_value){
    if(head==NULL) return false;
    
    Node *temp=head;
    bool found=false;

    while(temp!=NULL && !found){
        if(temp->data==previous)
            found =true;
        else
            temp=temp->next;
    }

    if(found)
        temp->data = new_value;

    return found ? true:false;
}

bool LinkList::udapte_at_index(int value, int index){
    if(index>=size) return false;

    Node *temp = head;

    for(int i=0;i<index;i++)
        temp = temp->next;
    
    temp->data = value;
    return true;
}