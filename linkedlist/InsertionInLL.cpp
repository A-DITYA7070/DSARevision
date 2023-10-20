/**
 * @file InsertionInLL.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class LinkedList{
    public:
    Node* InsertAtHead(Node* head,int data){
        Node* ptr=new Node(data);
        ptr->next=head;
        return ptr;
    }
    Node* InsertAtMid(Node* head,int data,int pos){
        if(head == NULL || head->next == NULL)return head;
        Node* ptr=head;
        int i=0;
        while(i!=pos-1){
            ptr=ptr->next;
            i++;
        }
        Node* temp=ptr->next;
        Node* x=new Node(data);
        ptr->next=x;
        x->next=temp;
        return head;
    }
    Node* InsertAtTail(Node* head,int data){
        if(head == NULL){
            Node* ptr = new Node(data);
            ptr->next=head;
            return ptr;
        }else{
            Node* temp=head;
            while(temp->next != NULL){
               temp=temp->next;
            }
            Node* newNode = new Node(data);
            temp->next=newNode;
            return head;
        }
    }
    
    void printList(Node* head);
};

void LinkedList::printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
}

int main(){
    Node* head=NULL;
    LinkedList obj;
    int t;
    cout<<"Enter the size of the list "<<endl;
    cin>>t;
    while(t--){
        int data;
        cin>>data;
        head=obj.InsertAtHead(head,data);
    }
    obj.printList(head);
    // inserting at tail...
    head=obj.InsertAtTail(head,12);
    cout<<endl;
    obj.printList(head);cout<<endl;
    // inserting at middle...
    head=obj.InsertAtMid(head,34,2);
    obj.printList(head);

    return 0;
}