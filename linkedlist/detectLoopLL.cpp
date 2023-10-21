/**
 * @file detectLoopLL.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief problem statement :-  detect whether a linked list contains loop or not...
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
    Node* createList(Node* head,int data){
        Node* ptr=new Node(data);
        ptr->next=head;
        return ptr;
    }

    void printLL(Node* head){
        Node* ptr=head;
        while(ptr != NULL){
            cout<<ptr->data<<"-->";
            ptr=ptr->next;
        }
    }

    bool isLoopInLL(Node* head){
        unordered_map<Node*,bool>vis;
        Node* ptr=head;
        while(ptr != NULL){
           if(vis[ptr]){
            return true;
           }else{
            vis[ptr]=true;
           }
           ptr=ptr->next;
        }
        return false;
    }

    Node* isLoop(Node* head){
        Node* slow=head;
        Node* fast=head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast=fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            if(fast == slow){
                return slow;
            }
        }
        return NULL;
    }

};

int main(){
    int n;
    cout<<"Enter the size of the list "<<endl;
    cin>>n;
    Node* head=NULL;
    LinkedList ll;
    while(n--){
        int data;
        cin>>data;
        ll.createList(head,data);
    }
    cout<<"Linked list contains list "<<ll.isLoopInLL(head)<<endl;
    Node* ptr=head;
    while(ptr->next != NULL)ptr=ptr->next;
    ptr->next = head->next;
    cout<<"Linked list contains list "<<ll.isLoopInLL(head)<<endl;
    return 0;
}