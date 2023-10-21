/**
 * @file reverseKItemsLL.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/**
 * Problem :- reverse k items in linkedlist..
 * ex:- 1->2->3->4->5->6->7 and k=2 then 
 *      2->1->4->3->6->5->7 will be output...
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
    Node* CreateLL(Node* head,int data){
        Node* temp=new Node(data);
        temp->next=head;
        return temp;
    }
    
    void printLL(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
    }

    Node* reverseLLInKGroups(Node* head,int k){
        if(head == NULL || head->next == NULL)return head;
        if(k==0)return head;
        Node* prev=NULL;
        Node* curr=head;
        Node* Next=NULL;
        int count=0;
        while(curr != NULL && count<k){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
            count++;
        }
        if(Next != NULL){
            head->next  = reverseLLInKGroups(Next,k);
        }
        return prev;
    }
};

int main(){
    int n;
    cout<<"Enter the size of the list "<<endl;
    cin>>n;
    int x=n;
    LinkedList ll;
    Node* head=NULL;
    while(n--){
        int data;
        cin>>data;
        head=ll.CreateLL(head,data);
    }
    ll.printLL(head);cout<<endl;
    int k;
    cout<<"Enter the value of k to reverse the node "<<endl;
    cin>>k;
    if(k>x){
        k=k%x;
    }
    head=ll.reverseLLInKGroups(head,k);
    ll.printLL(head);
    return 0;
}