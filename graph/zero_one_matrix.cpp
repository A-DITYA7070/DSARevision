/**
 * @file zero_one_matrix.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * Problem statement :- Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell. 
 * The distance between two adjacent cells is 1.
 * 
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 */
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> minDistance(vector<vector<int>>&mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>ans(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                q.push({{i,j},0});
                vis[i][j]=1;
            }
        }
    }

    int delrow[4]={-1,1,0,0};
    int delcol[4]={0,0,-1,1};

    while(!q.empty()){
        auto it=q.front();
        q.pop();
        int row=it.first.first;
        int col=it.first.second;
        int step=it.second;
        ans[row][col]=step;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol]==0){
                q.push({{nrow,ncol},step+1});
                vis[nrow][ncol]=1;
            }
        }
    }
    return ans;
}
int main(){
    int n,m;
    cout<<"Enter the size of the row and column "<<endl;
    cin>>n>>m;
    vector<vector<int>>mat;
    cout<<"Enter the matrix "<<endl;
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        mat.push_back(temp);
        temp.clear();
    }
    vector<vector<int>> ans = minDistance(mat);
    cout<<"Matrix after minimum distance is : "<<endl;
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }cout<<endl;
    }
    return 0;
}