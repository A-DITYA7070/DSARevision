/**
 * @file Traversals.cpp
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

class BinaryTree{
    public:
    int data;
    BinaryTree* right;
    BinaryTree* left;
    BinaryTree(int data){
        this->data = data;
        this->right=NULL;
        this->left=NULL;
    }
};

class BTTraversals{
    public:
    void inorder(BinaryTree* root){
        if(root == NULL)return;
        inorder(root->left);
        cout<<root->data<<"-->";
        inorder(root->right);
    }

    void preorder(BinaryTree* root){
        if(root == NULL)return;
        cout<<root->data<<"-->";
        preorder(root->left);
        preorder(root->right);
    }

    void postOrder(BinaryTree* root){
        if(root == NULL)return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<"-->";
    }

    void levelOrder(BinaryTree* root){
        if(root == NULL)return;
        queue<BinaryTree*>q;
        q.push(root);
        while(!q.empty()){
            BinaryTree* f=q.front();
            q.pop();
            cout<<f->data<<"-->";
            if(f->left!=NULL){
                q.push(f->left);
            }
            if(f->right!=NULL){
                q.push(f->right);
            }
        }
    }

    BinaryTree* createTree(BinaryTree* root,int data){
        if(root == NULL){
            root = new BinaryTree(data);
            return root;
        }else if(root -> left == NULL){
            root->left=new BinaryTree(data);
            return root;
        }else{
            root -> right = new BinaryTree(data);
            return root;
        }
    }
    
};

int main(){
 int n;
 cin>>n;
 BinaryTree* root=NULL;
 BTTraversals obj;
 while(n--){
    int data;
    cin>>data;
    root=obj.createTree(root,data);
 }
 obj.inorder(root);
 cout<<endl;
 obj.preorder(root);
 cout<<endl;
 obj.postOrder(root);
 cout<<endl;
 obj.levelOrder(root);
 return 0;
}