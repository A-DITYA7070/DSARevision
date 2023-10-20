/**
 * @file ReverseLL.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// i guess u know what to do...

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
        Node* newNode =  new Node(data);
        newNode->next=head;
        return newNode;
    }
    void printList(Node* head){
        Node* ptr=head;
        while(ptr != NULL){
            cout<<ptr->data<<"-->";
            ptr=ptr->next;
        }
    }
    
    /**
     * @brief Function to reverse a linked list .. 
     */
    Node* reverseLL(Node* head){
        if(head  == NULL || head->next == NULL)return head;
        Node* prev=NULL;
        Node* curr=head;
        Node* Next=NULL;
        while(curr != NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
};
int  main(){
    int n;
    cout<<"Enter the size of the list "<<endl;
    cin>>n;
    Node* head=NULL;
    LinkedList obj;
    while(n--){
        cout<<"Enter the data to insert in dynamic linked list "<<endl;
        int x;
        cin>>x;
        head=obj.InsertAtHead(head,x);
    }
    obj.printList(head);cout<<endl;
    //reversing the linked list ... 
    head = obj.reverseLL(head);
    obj.printList(head);

    return 0;
}