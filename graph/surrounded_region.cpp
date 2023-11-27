/**
 * @file surrounded_region.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * problem statement :- Given an m x n matrix board containing 'X' and 'O', capture all regions that are 
 *                      4-directionally surrounded by 'X'.A region is captured by flipping all 'O's into 'X's 
 *                      in that surrounded region.
 * 
 *                  Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
                    Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
                    Explanation: Notice that an 'O' should not be flipped if:
                    - It is on the border, or
                    - It is adjacent to an 'O' that should not be flipped.
                    The bottom 'O' is on the border, so it is not flipped.
                    The other three 'O' form a surrounded region, so they are flipped.
 * 
 */

#include<bits/stdc++.h>
using namespace std;
void dfs(int row,int col,int n,int m,int delrow[],int delcol[],vector<vector<char>>&board,vector<vector<int>>&vis){
     vis[row][col]=1;
     for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol]=='O' && !vis[nrow][ncol]){
            dfs(nrow,ncol,n,m,delrow,delcol,board,vis);
        }
     }
}
void solve(vector<vector<char>>& board){
    int n=board.size();
    int m=board[0].size();
    int delrow[4]={-1,1,0,0};
    int delcol[4]={0,0,-1,1};
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        if(board[i][0] == 'O' && !vis[i][0]){
            dfs(i,0,n,m,delrow,delcol,board,vis);
        }
        if(board[i][m-1] == 'O' && !vis[i][m-1]){
            dfs(i,m-1,n,m,delrow,delcol,board,vis);
        }
    }
    for(int j=0;j<m;j++){
        if(board[0][j] == 'O' && !vis[0][j]){
            dfs(0,j,n,m,delrow,delcol,board,vis);
        }
        if(board[n-1][j] == 'O' && !vis[n-1][j]){
            dfs(n-1,j,n,m,delrow,delcol,board,vis);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                board[i][j]='X';
            }
        }
    }
}
int main(){
int n,m;
cout<<"Enter the size of row and col "<<endl;
cin>>n>>m;
vector<vector<char>>board;
cout<<"Enter the matrix/board "<<endl;
for(int i=0;i<n;i++){
    vector<char>temp;
    for(int j=0;j<m;j++){
        char x;
        cin>>x;
        temp.push_back(x);
    }
    board.push_back(temp);
    temp.clear();
}
solve(board);
cout<<"The redefined board is "<<endl;
for(auto it:board){
   for(auto i:it){
     cout<<i<<" ";
   }cout<<endl;
}
return 0;
}