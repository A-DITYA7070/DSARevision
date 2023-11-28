/**
 * @file noOfEnclaves.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem statement :- You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
 *                      A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking
 *                      off the boundary of the grid.Return the number of land cells in grid for which we cannot walk off the 
 *                      boundary of the grid in any number of moves.
 *                      Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
                        Output: 3
                        Explanation: There are three 1s that are enclosed by 0s, and one 1 
                                    that is not enclosed because its on the boundary.
 * 
 */


#include<bits/stdc++.h>
using namespace std;
void dfs(int row,int col,int n,int m,int delrow[],int delcol[],vector<vector<int>>&grid,vector<vector<int>>&vis){
    vis[row][col]=1;
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
            dfs(nrow,ncol,n,m,delrow,delcol,grid,vis);
        }
    }
}
int main(){
cout<<"Enter the size of row and column "<<endl;
int n,m;
cin>>n>>m;
vector<vector<int>>grid;
cout<<"Enter the grid "<<endl;
for(int i=0;i<n;i++){
    vector<int>temp;
    for(int j=0;j<m;j++){
        int x;
        cin>>x;
        temp.push_back(x);
    }
    grid.push_back(temp);
    temp.clear();
}
int delrow[4]={0,0,-1,1};
int delcol[4]={-1,1,0,0};
vector<vector<int>>vis(n,vector<int>(m,0));
int ans=0;
for(int i=0;i<n;i++){
    if(!vis[i][0] && grid[i][0] == 1){
        dfs(i,0,n,m,delrow,delcol,grid,vis);
    }
    if(!vis[i][m-1] && grid[i][m-1]==1){
        dfs(i,m-1,n,m,delrow,delcol,grid,vis);
    }
}
for(int j=0;j<m;j++){
    if(!vis[0][j] && grid[0][j] == 1){
        dfs(0,j,n,m,delrow,delcol,grid,vis);
    }
    if(!vis[0][n-1] && grid[0][n-1] == 1){
        dfs(0,n-1,n,m,delrow,delcol,grid,vis);
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(!vis[i][j] && grid[i][j] == 1){
            ans++;
        }
    }
}
cout<<"No of enclaves "<<ans<<endl;
return 0;
}