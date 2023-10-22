/**
 * @file checkPallindromeLL.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Approach :-
 *         1. use array and check if its pallindrome or not.. t.c O(n);
 *         2. a).find the middle of the ll.
 *            b).reverse the list from middle->next pointer..
 *            c).iterate from head and from middle->next if not matched not pallindrome else pallindrome..
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
        if(head == NULL){
            Node* curr=new Node(data);
            curr->next=head;
            return curr;
        }else{
            Node* temp=head;
            while(temp->next != NULL){
                temp=temp->next;
            }
            Node* curr=new Node(data);
            temp->next=curr;
            return head;
        }
     }

     void printLL(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
     }
     /**
      * Naive approach...
      * function to detect whether the list is pallindrome or not..
      * t.c :- O(n);
      * s.c :- O(n);
      */
     bool isPallindrome(Node* head){
        vector<int>temp;
        Node* curr=head;
        while(curr != NULL){
            temp.push_back(curr->data);
            curr=curr->next;
        }
        int i=0;
        int j=temp.size()-1;
        while(i<=j){
            if(temp[i]!=temp[j])return false;
            i++;
            j--;
        }
        return true;
     }
     
     /**
      * step 1. find middle of the ll..
      * middle of the ll using hair and tortoise method...
      */
     Node* middleLL(Node* head){
        if(head == NULL || head->next == NULL)return head;
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
            }
            slow=slow->next;
        }
        return slow;
     }
     
     /**
      * step 2. reverse from middle of the ll..
      * method to reverse the ll...
      */
     Node* reverseLL(Node* head){
        if(head == NULL || head->next == NULL)return head;
        Node* curr=head;
        Node* prev=NULL;
        Node* Next=NULL;
        while(curr != NULL){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
     }

     /**
      * function to check whether the ll is pallindrome or not... 
      */
     bool isPallindromeOptimal(Node* head){
        if(head == NULL)return true;
        if(head->next == NULL)return true;
        Node* mid = middleLL(head);
        Node* revLL = reverseLL(mid->next);
        Node* start = head;
        while(revLL != NULL){
            if(start->data != revLL->data)return false;
            start=start->next;
            revLL=revLL->next;
        }
        return true;
     }
};

int main(){
    int n;
    cout<<"enter the len of list "<<endl;
    cin>>n;
    Node* head=NULL;
    LinkedList obj;
    cout<<"enter the data of the list "<<endl;
    while(n--){
        int data;
        cin>>data;
        head=obj.createLL(head,data);
    }
    cout<<obj.isPallindrome(head)<<endl;
    cout<<obj.isPallindromeOptimal(head)<<endl;
    return 0;
}