/**
 * @file lengthOfLL.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-22
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
   Node* createLL(Node* head,int data){
     Node* curr=new Node(data);
     curr->next=head;
     return curr;
   }
   void printLL(Node* head){
     Node* ptr=head;
     while(ptr!=NULL){
        cout<<ptr->data<<"-->";
        ptr=ptr->next;
     }
   }
   int lengthOfLL(Node* head){
      if(head == NULL)return 0;
      int len=0;
      Node* ptr=head;
      while(ptr != NULL){
        len++;
        ptr=ptr->next;
      }
      return len;
   }
};

int main(){
    int n;
    cout<<"Enter the length of list "<<endl;
    cin>>n;
    Node* head=NULL;
    LinkedList obj;
    cout<<"Enter the list..."<<endl;
    while(n--){
        int data;
        cin>>data;
        head=obj.createLL(head,data);
    }
    cout<<"Length of linkedlist is : "<<obj.lengthOfLL(head)<<endl;
    return 0;
}