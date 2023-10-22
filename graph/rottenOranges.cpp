/**
 * @file rottenOranges.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-20
 * @copyright Copyright (c) 2023
 */

/**
 * problem statement :- 
 * Problem Statement: You will be given an m x n grid, where each cell has the following values : 
    2  –  represents a rotten orange
    1  –  represents a Fresh orange
    0  –  represents an Empty Cell
    Every minute, if a Fresh Orange is adjacent to a Rotten Orange in 4-direction ( upward, downwards, right, and left ) 
    it becomes Rotten. 
    Return the minimum number of minutes required such that none of the cells has a Fresh Orange. If it’s not possible, return -1.
 
    Ex :- Input: grid - [ [2,1,1] , [1,1,0] , [0,1,1] ] 
          Output:  4
 */

/**
 * Approach: 
    -> First of all we will create a Queue data structure to store coordinate of Rotten Oranges
        We will also have variables as:

        Total_oranges – It will store total number of oranges in the grid ( Rotten + Fresh )
        Count – It will store the total number of oranges rotten by us . 
        Total_time – total time taken to rotten.

    -> After this, we will traverse the whole grid and count the total number of 
    oranges in the grid and store it in Total_oranges. Then we will also push the rotten oranges 
    in the Queue data structure as well.

    -> Now while our queue is not empty,  we will pick up each Rotten Orange 
    and check in all its 4 directions whether a Fresh orange is present or not. 
    If it is present we will make it rotten and push it in our queue data structure 
    and pop out the Rotten Orange which we took up as its work is done now.

    -> Also we will keep track of the count of rotten oranges we are getting.

    -> If we rotten some oranges, then obviously our queue will not be empty. 
       In that case, we will increase our total time. This goes on until our queue becomes empty. 

    -> After it becomes empty, We will check whether the total number of oranges 
    initially is equal to the current count of oranges. If yes, we will return the total 
    time taken, else will return -1 because some fresh oranges are still left and can’t be made rotten.
 * 
 */

/**
 *  if traversal in four direction ( -|- ) i.e ( up down left and right ) is needed use this concept 
 *  ( VVI ) :- 
 *              int dx[4] = {-1,0,1,0};
                int dy[4] = {0,1,0,-1};
 */

#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int rottenOranges(vector<vector<int>>&edges){

      int n=edges.size();
      int m=edges[0].size();

      queue<pair<pair<int,int>,int>>q;
      int vis[n][m];

      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            if(edges[i][j]==2){
               q.push({{i,j},0});
               vis[i][j]=2;
            }else if(edges[i][j]==1){
               vis[i][j]=1;
            }else{
               vis[i][j]=0;
            }
         }
      }

      int tm=0;
      int dx[4]={-1,0,1,0};
      int dy[4]={0,1,0,-1};

      while(!q.empty()){
         int r=q.front().first.first;
         int c=q.front().first.second;
         int t=q.front().second;
         tm=max(tm,t);
         q.pop();

         for(int i=0;i<4;i++){
            int nrow=r+dx[i];
            int ncol=c+dy[i];
            if(
               nrow >=0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               edges[nrow][ncol] != 2 &&
               edges[nrow][ncol] == 1
            ){
               q.push({{nrow,ncol},t+1});
               vis[nrow][ncol]=2;
            }
         }
      }
       
      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            if(vis[i][j] != 2 && edges[i][j] == 1){
               return -1;
            }
         }
      }
      return tm;
    }
};

int main(){

   Graph obj;

   int n;
   cout<<"Enter the size of the matrix "<<endl;
   cin>>n;
   vector<vector<int>>edges;
   for(int i=0;i<n;i++){
      vector<int>temp;
      cout<<"Enter the "<<i+1<<" th row "<<endl;
      for(int j=0;j<n;j++){
         int x;
         cin>>x;
         temp.push_back(x);
      }
      edges.push_back(temp);
      temp.clear();
   }
   
   cout<<"The min time required to rotten all oranges is "<<obj.rottenOranges(edges)<<endl;

   return 0;
}